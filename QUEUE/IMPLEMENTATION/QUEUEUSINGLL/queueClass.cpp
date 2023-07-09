#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class Queue
{
private:
    struct Node *front;
    struct Node *rear;
    int queueSize;

public:
    Queue();

    void enqueue(int data);
    void dequeue();
    bool isEmpty();
    void display();
    int queueFront();
    int queueRear();
    int size();
};

Queue::Queue()
{
    front = NULL;
    rear = NULL;
    queueSize = 0;
}

// LINKED LIST INSERT LAST FUNCTION
void Queue::enqueue(int data)
{
    struct Node *newn = new Node;

    newn->data = data;
    newn->next = NULL;

    if (front == NULL)
    {
        front = newn;
    }
    else
    {
        rear->next = newn;
    }

    rear = newn;

    queueSize++;
}

// LINKED LIST DELETE FIRST FUNCTION
void Queue::dequeue()
{
    if (front == NULL)
    {
        cout << "queue IS EMPTY!\n";
    }

    else if (((front)->next) == NULL)
    {
        delete (front);
        front = NULL;
        rear = NULL;
        queueSize--;
    }

    else
    {
        struct Node *temp = front;

        (front) = (front)->next;

        delete (temp);
        queueSize--;
    }
}

// TO CHECK IF queue IS EMPTY
bool Queue::isEmpty()
{
    if (front == NULL)
        return true;

    return false;
}

// TO DISPLAY THE CONTENTS OF QUEUE
void Queue::display()
{
    struct Node *temp = front;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int Queue::queueFront()
{
    if (front == NULL)
        return -000;

    return front->data;
}

int Queue::queueRear()
{
    if (rear == NULL)
        return -000;

    return rear->data;
}

int Queue::size()
{
    return queueSize;
}

int main()
{
    Queue queue;

    queue.enqueue(40);
    queue.enqueue(30);
    queue.enqueue(50);
    queue.enqueue(20);
    queue.enqueue(10);

    queue.display();

    cout << "FRONT OF QUEUE IS : " << queue.queueFront() << endl;
    cout << "REAR OF QUEUE IS : " << queue.queueRear() << endl;
    cout << "SIZE OF QUEUE IS : " << queue.size() << endl;

    cout << "/---------------------------------------------------------------/" << endl;

    queue.dequeue();
    queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();

    queue.display();

    cout << "FRONT OF QUEUE IS : " << queue.queueFront() << endl;
    cout << "REAR OF QUEUE IS : " << queue.queueRear() << endl;
    cout << "SIZE OF QUEUE IS : " << queue.size() << endl;

    cout << "/---------------------------------------------------------------/" << endl;

    return 0;
}