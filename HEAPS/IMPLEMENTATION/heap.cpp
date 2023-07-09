#include <iostream>

using namespace std;

class Heap
{
public:
    int heap[100];
    int size;

    Heap()
    {
        heap[0] = -1;
        size = 0;
    }

    // TC : O(N * LOG N)
    void insertIntoHeap(int data)
    {
        size += 1;
        int index = size;
        heap[index] = data;

        while (index > 1)
        {
            int parent = index / 2;
            if (heap[parent] < heap[index])
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
                return;
        }
    }

    // TC : O(N * LOG N)
    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        int index = 1;
        heap[index] = heap[size];
        size--;

        while (index < size)
        {

            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            if (leftIndex <= size && rightIndex <= size) // dono child he kya ??
            {
                if (heap[leftIndex] < heap[rightIndex] && heap[rightIndex] > heap[index])
                {
                    swap(heap[rightIndex], heap[index]);
                    index = rightIndex;
                }
                else if (heap[leftIndex] > heap[rightIndex] && heap[leftIndex] > heap[index])
                {
                    swap(heap[leftIndex], heap[index]);
                    index = leftIndex;
                }
                else
                {
                    return; // dono child h pr dono parent se vadde nhi hunde
                }
            }
            else if (leftIndex <= size && heap[leftIndex] > heap[index]) // only left h
            {
                swap(heap[index], heap[leftIndex]);
                index = leftIndex;
            }
            else if (rightIndex <= size && heap[rightIndex] > heap[index]) // only right h
            {
                swap(heap[index], heap[rightIndex]);
                index = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void displayHeap()
    {
        for (int i = 1; i <= size; ++i)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap heap;

    heap.insertIntoHeap(45);
    heap.insertIntoHeap(55);
    heap.insertIntoHeap(35);
    heap.insertIntoHeap(75);
    heap.insertIntoHeap(65);
    heap.displayHeap();

    heap.deleteFromHeap();
    heap.displayHeap();

    return 0;
}