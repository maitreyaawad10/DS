#include <bits/stdc++.h>

using namespace std;

// QUICKSELECT ALGO
// TC: O(N) IN AVG CASE
// SC: O(LOG N)
int partition(vector<int> &arr, int start, int end)
{
    int i = start, j = start;
    int pivot = arr[end];

    while (i < end)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[j], arr[i]);
            j++;
        }

        i++;
    }
    swap(arr[j], arr[end]);

    return j;
}

int quickSelect(vector<int> &arr, int k, int size, int start, int end)
{
    int pivot = partition(arr, start, end);

    if (pivot < (size - k))
        return quickSelect(arr, k, size, pivot + 1, end);

    else if (pivot > (size - k))
        return quickSelect(arr, k, size, start, pivot - 1);

    else
        return arr[pivot];
}

int findKthLargest(vector<int> &nums, int k)
{
    int size = nums.size();

    return quickSelect(nums, k, size, 0, size - 1);
}

// TC: O(N) + O(K * LOG N)
// SC: O(N)
void heapify(vector<int> &heap, int size, int index)
{
    int currIndex = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if (left < size && heap[left] > heap[currIndex])
        currIndex = left;

    if (right < size && heap[right] > heap[currIndex])
        currIndex = right;

    if (currIndex != index)
    {
        swap(heap[currIndex], heap[index]);
        heapify(heap, size, currIndex);
    }
}

void buildHeap(vector<int> &heap, int size)
{
    for (int i = (size / 2) - 1; i >= 0; --i)
    {
        heapify(heap, size, i);
    }
}

int heapSort(vector<int> &heap, int k)
{
    int size = heap.size();

    while (k > 1)
    {
        int last = size - 1;

        // step 1:
        swap(heap[0], heap[last]);

        // step 3:
        size--;

        // step 2:
        heapify(heap, size, 0);

        k--;
    }

    return heap[0];
}

int findKthLargest(vector<int> &nums, int k)
{
    int size = nums.size();

    buildHeap(nums, size);

    return heapSort(nums, k);
}