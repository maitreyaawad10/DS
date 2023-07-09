#include <bits/stdc++.h>

using namespace std;

class Queue
{
    int *arr;
    int size;
    int qFront;
    int qRear;

public:
    Queue()
    {
        size = 100001;
        arr = new int[size];
        qFront = 0;
        qRear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        if (qFront == qRear)
            return true;

        return false;
    }

    void enqueue(int data)
    {
        if (qRear == size)
        {
            cout << "Queue is full!" << endl;
        }
        else
        {
            arr[qRear] = data;
            qRear++;
        }
    }

    int dequeue()
    {
        if (qFront == qRear)
        {
            // cout << "Queue is empty!" << endl;
            return -1;
        }
        else
        {
            int top = arr[qFront];
            arr[qFront] = -1;
            qFront++;
            if (qFront == qRear)
            {
                qFront = 0;
                qRear = 0;
            }
            return top;
        }
    }

    int front()
    {
        if (qFront == qRear)
        {
            // cout << "Queue is empty!" << endl;
            return -1;
        }
        else
        {
            int top = arr[qFront];
            return top;
        }
    }
};