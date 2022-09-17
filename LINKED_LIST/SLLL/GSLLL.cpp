#include <iostream>
#include <string.h>

using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SLLL
{
private:
    struct node<T> *Head;
    int Countnode;

public:
    SLLL();

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
SLLL<T>::SLLL()     // Constructor
{
    Head = NULL;
    Countnode = 0;
}

template <class T>
void SLLL<T>::InsertFirst(T value)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

    newn->data = value;
    newn->next = NULL;

    if (Head == NULL) // IF LL IS EMPTY
    {
        Head = newn;
    }

    else // IF LL IS NOT EMPTY
    {
        newn->next = Head;
        Head = newn;
    }

    Countnode++;
}

template <class T>
void SLLL<T>::InsertLast(T value)
{
    struct node<T> *newn = NULL, *temp = NULL;

    newn = new node<T>;

    newn->data = value;
    newn->next = NULL;

    if (Head == NULL) // IF LL IS EMPTY
    {
        Head = newn;
    }

    else // IF LL IS NOT EMPTY
    {
        temp = Head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    Countnode++;
}

template <class T>
void SLLL<T>::DeleteFirst()     // IF LL IS EMPTY
{
    if (Head == NULL)       
    {
        return;
    }

    else        // IF LL CONTAINS ATLEAST 1 NODE
    {
        struct node<T>  *temp = Head;

        Head = Head->next;
        delete temp;
    }

    Countnode--;
}

template <class T>
void SLLL<T>::DeleteLast()
{
    if (Head == NULL)       // IF LL IS EMPTY
    {
        return;
    }

    else if (Countnode == 1)        // IF LL CONTAINS ONLY 1 NODE
    {
        delete Head;
        Head = NULL;
    }

    else        // IF LL CONTAINS MORE THAN 1 NODE
    {
        struct node<T> *temp = Head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    Countnode--;
}

template <class T>
void SLLL<T>::InsertAtPos(T value, int pos)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

    newn->data = value;
    newn->next = NULL;

    if (pos < 1 || pos > (Countnode + 1))
    {
        cout << "Invalid position!\n";
        return;
    }

    if (pos == 1)       // InsertFirst
    {
        InsertFirst(value);
    }

    else if (pos == Countnode + 1)      // InsertLast
    {
        InsertLast(value);
    }

    else         // Inserting at any random position
    {
        struct node<T> *temp = Head;

        for (int i = 1; i < (pos - 1); i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        Countnode++;
    }
}

template <class T>
void SLLL<T>::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > Countnode)
    {
        cout << "Invalid position!\n";
        return;
    }

    if (pos == 1)       // DeleteFirst
    {
        DeleteFirst();
    }

    else if (pos == Countnode)      // DeleteLast
    {
        DeleteLast();
    }

    else             // Deleting at any random position
    {
        struct node<T> *temp = Head;

        for (int i = 1; i < (pos - 1); i++)
        {
            temp = temp->next;
        }

        struct node<T> *tempdelete = temp->next;
        temp->next = temp->next->next;
        delete tempdelete;

        Countnode--;
    }
}

template <class T>
void SLLL<T>::Display()      // To display the LL
{
    struct node<T> *temp = Head;
    
    cout << "Elements of Linked list are : \n";
    
    if(Head == NULL)		// If LL is empty
    {
    	return;
    }
    
    do
    {
    	cout << "| " << temp -> data << " | -> ";
    	temp = temp -> next;
    }
    while(temp != NULL);
    
    cout << "NULL" << "\n";
}

template <class T>
int SLLL<T>::Count()        // To count number of nodes in LL
{
    return Countnode;
}

int main()
{
    SLLL <string>obj;
    int choice = 1, pos = 0;
    string value;

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