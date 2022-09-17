#include <iostream>

using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DLLL
{
private:
    struct node<T> *Head;
    int CountNode;

public:
    DLLL();

    void InsertFirst(T);
    void InsertLast(T);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T, int);
    void DeleteAtPos(int);

    void Display();
    int Count();
};

template <class T>
DLLL<T>::DLLL()     // Constructor
{
    Head = NULL;
    CountNode = 0;
}

template <class T>
void DLLL<T>::InsertFirst(T value)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

    newn -> data = no;
    newn -> prev = NULL;
    newn -> next = NULL;

    if(Head == NULL)         // If LL is empty
    {
        Head = newn;
    }

    else        // If LL contains atleast 1 element
    {
        newn -> next = Head;
        Head -> prev = newn;
        Head = newn;
    }

    CountNode++;
}

template <class T>
void DLLL<T>::InsertLast(T value)
{
    struct node<T>*newn = NULL;

    newn = new node<T>;

    newn -> data = no;
    newn -> prev = NULL;
    newn -> next = NULL;

    if(Head == NULL)         // If LL is empty
    {
        Head = newn;
    }

    else if(Head -> next == NULL && Head -> prev == NULL)       // If LL contains only 1 element
    {
        Head -> next = newn;
        newn -> prev = Head;
    }

    else        // If LL contains more than 1 element
    {
        struct node * temp = Head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> prev = temp;
    }

    CountNode++;
}

template <class T>
void DLLL<T>::DeleteFirst()
{
    if(Head == NULL)         // If LL is empty
    {
        return;
    }

    else if(Head -> next == NULL && Head -> prev == NULL)       // If LL contains only 1 element
    {
        delete Head;
        Head = NULL;
    }

    else        // If LL contains more than 1 element
    {
        Head = Head -> next;
        delete Head -> prev;
        Head -> prev = NULL;
    }

    CountNode--;
}

template <class T>
void DLLL<T>::DeleteLast()
{
    if(Head == NULL)         // If LL is empty
    {
        return;
    }

    else if(Head -> next == NULL && Head -> prev == NULL)       // If LL contains only 1 element
    {
        delete Head;
        Head = NULL;
    }

    else        // If LL contains more than 1 element
    {
        struct node<T> *temp = Head;

        while (temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        
        delete temp -> next;
        temp -> next = NULL;
    }

    CountNode--;
}

template <class T>
void DLLL<T>::InsertAtPos(T value, int pos)
{
    if(pos < 1 || pos > (CountNode+1))
    {
        cout << "Inavlid position!\n";
        return;
    }

    if(pos == 1)        // InsertFirst
    {
        InsertFirst(value);
    }

    else if(pos == CountNode+1)     // InsertLast
    {
        InsertLast(value);
    }

    else        // Inserting at any random position
    {
        struct node<T> *newn = new node<T>;

        newn -> data = no;
        newn -> prev = NULL;
        newn -> next = NULL;

        struct node<T> *temp = Head;

        for(int i = 1; i < (pos-1); i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        newn -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;

        CountNode++;
    }
}

template <class T>
void DLLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > CountNode)
    {
        cout << "Inavlid position!\n";
        return;
    }

    if(pos == 1)        // DeleteFirst
    {
        DeleteFirst();
    }

    else if(pos == CountNode)       // DeleteLast
    {
        DeleteLast();
    }

    else        // Deleting at any random position
    {
        struct node<T> *temp = Head;

        for(int i = 1; i < (pos-1); i++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        CountNode--;
    }
}

template <class T>
void DLLL<T>::Display()     // To display the LL
{
    struct node<T> *temp = Head;

    if(Head == NULL){
        return;
    }

    do
    {
        cout << "| " << temp -> data << " | -> ";
        temp = temp -> next;
    } 
    while (temp != NULL);
    
    cout << "NULL\n";
}

template <class T>
int DLLL<T>::Count()        // To count number of nodes in LL
{
    return CountNode;
}

int main()
{
    DLLL <int>obj;
    int choice = 1, value = 0, pos = 0;

    while (choice != 0)
    {
        cout << "Choose from following options : " << endl;

        cout << "1. InsertFirst\n";
        cout << "2. DeleteFirst\n";
        cout << "3. InsertLast\n";
        cout << "4. DeleteLast\n";
        cout << "5. InsertAtPos\n";
        cout << "6. DeleteAtPos\n";
        cout << "7. Display the linked list\n";
        cout << "8. Count the number of nodes\n";
        cout << "9. Exit\n";
        
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value : ";
                cin >> value;
                obj.InsertFirst(value);
                cout << "----------------------------------------------------------\n";
                break;

            case 2:
                obj.DeleteFirst();
                cout << "----------------------------------------------------------\n";
                break;

            case 3:
                cout << "Enter value : ";
                cin >> value;
                obj.InsertLast(value);
                cout << "----------------------------------------------------------\n";
                break;

            case 4:
                obj.DeleteLast();
                cout << "----------------------------------------------------------\n";
                break;

            case 5:
                cout << "Enter value : ";
                cin >> value;
                cout << "Enter position : ";
                cin >> pos;
                obj.InsertAtPos(value, pos);
                cout << "----------------------------------------------------------\n";
                break;

            case 6:
                cout << "Enter position : ";
                cin >> pos;
                obj.DeleteAtPos(pos);
                cout << "----------------------------------------------------------\n";
                break;

            case 7:
                cout << "----------------------------------------------------------\n";
                obj.Display();
                cout << "----------------------------------------------------------\n";
                break;

            case 8:
                cout << "----------------------------------------------------------\n";
                cout <<  "Number of nodes are : " << obj.Count() << endl;
                cout << "----------------------------------------------------------\n";
                break;

            case 9:
                cout << "Thank you!" << endl;
                choice = 0;
                cout << "----------------------------------------------------------\n";
                break;

            default:
                cout << "Invalid choice!\n";
                cout << "----------------------------------------------------------\n";
                break;
        }
    }

    return 0;
}