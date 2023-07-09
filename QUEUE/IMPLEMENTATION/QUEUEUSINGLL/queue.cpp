#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// LINKED LIST INSERT LAST FUNCTION
void enqueue(struct Node **Head, struct Node **Tail, int data)
{
    struct Node *newn = new Node;

    newn->data = data;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        // struct Node *temp = *Head;

        // while (temp->next != NULL)
        // {
        //     temp = temp->next;
        // }

        // temp->next = newn;
        (*Tail)->next = newn; // O(1) TC INSTEAD OF O(N)
    }

    *Tail = newn;
}

// LINKED LIST DELETE FIRST FUNCTION
void dequeue(struct Node **Head, struct Node **Tail)
{
    if (*Head == NULL)
    {
        cout << "STACK IS EMPTY!\n";
    }

    else if (((*Head)->next) == NULL)
    {
        delete (*Head);
        *Head = NULL;
        *Tail = NULL;
    }

    else
    {
        struct Node *temp = *Head;

        (*Head) = (*Head)->next;

        delete (temp);
    }
}

// TO CHECK IF STACK IS EMPTY
bool isEmpty(struct Node **head)
{
    if (*head == NULL)
        return true;

    return false;
}

// TO DISPLAY THE CONTENTS OF STACK
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{
    struct Node *front = NULL;
    struct Node *rear = NULL;

    enqueue(&front, &rear, 40);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 50);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 10);

    display(front);

    front == NULL ? cout << "FRONT OF QUEUE IS : "
                         << "NULL"
                  : cout << "FRONT OF QUEUE IS : " << front->data;
    cout << endl;

    rear == NULL ? cout << "REAR OF QUEUE IS : "
                        << "NULL"
                 : cout << "REAR OF QUEUE IS : " << rear->data;
    cout << endl;

    cout << "/---------------------------------------------------------------/" << endl;

    dequeue(&front, &rear);
    dequeue(&front, &rear);
    // dequeue(&front, &rear);
    // dequeue(&front, &rear);
    // dequeue(&front, &rear);
    // dequeue(&front, &rear);

    display(front);

    front == NULL ? cout << "FRONT OF QUEUE IS : "
                         << "NULL"
                  : cout << "FRONT OF QUEUE IS : " << front->data;
    cout << endl;

    rear == NULL ? cout << "REAR OF QUEUE IS : "
                        << "NULL"
                 : cout << "REAR OF QUEUE IS : " << rear->data;
    cout << endl;

    cout << "/---------------------------------------------------------------/" << endl;

    return 0;
}