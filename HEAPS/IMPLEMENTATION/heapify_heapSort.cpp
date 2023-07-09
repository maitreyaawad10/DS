#include <iostream>

using namespace std;

void heapify(int arr[], int size, int index)
{
    int currIndex = index;
    int leftChild = 2 * currIndex;
    int rightChild = 2 * currIndex + 1;

    if (leftChild <= size && arr[currIndex] < arr[leftChild])
    {
        currIndex = leftChild;
    }

    if (rightChild <= size && arr[currIndex] < arr[rightChild])
    {
        currIndex = rightChild;
    }

    if (currIndex != index)
    {
        swap(arr[currIndex], arr[index]);
        heapify(arr, size, currIndex);
    }
}

void buildHeap(int arr[], int size)
{
    for (int i = size / 2; i >= 1; --i)
    {
        heapify(arr, size, i);
    }
}

void heapSort(int arr[], int size)
{
    while (size > 1)
    {
        swap(arr[1], arr[size]);

        size--;

        heapify(arr, size, 1);
    }
}

void printHeap(int arr[], int size)
{
    for (int i = 1; i <= size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int size = 5;
    // int arr[7] = {-1, 3, 2, 1, 5, 6, 4};
    // int size = 6;

    buildHeap(arr, size);
    printHeap(arr, size);

    heapSort(arr, size);
    printHeap(arr, size);

    return 0;
}