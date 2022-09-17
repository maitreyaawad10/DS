#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE;

class SLLL
{
private:
    PNODE Head;
    int CountNode;

public:
    SLLL();

    void InsertFirst(int);
    void InsertLast(int);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(int, int);
    void DeleteAtPos(int);

    void Display();
    int Count();
};

SLLL::SLLL()        // Constructor
{
    Head = NULL;
    CountNode = 0;
}

void SLLL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)   // IF LL IS EMPTY
    {
        Head = newn;
    }

    else    // IF LL IS NOT EMPTY
    {
        newn->next = Head;
        Head = newn;
    }

    CountNode++;
}

void SLLL::InsertLast(int no)
{
    PNODE newn = NULL, temp = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)   // IF LL IS EMPTY
    {
        Head = newn;
    }

    else    // IF LL IS NOT EMPTY
    {
        temp = Head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    CountNode++;
}

void SLLL::DeleteFirst()
{
    if (Head == NULL)       // IF LL IS EMPTY
    {
        return;
    }

    else        // IF LL IS NOT EMPTY
    {
        PNODE temp = Head;

        Head = Head->next;
        delete temp;
    }

    CountNode--;
}

void SLLL::DeleteLast()
{
    if (Head == NULL)       // IF LL IS EMPTY
    {
        return;
    }

    else if (CountNode == 1)        // IF LL HAS ONLY 1 NODE
    {
        delete Head;
        Head = NULL;
    }

    else        // IF LL HAS MORE THAN 1 NODE
    {
        PNODE temp = Head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    CountNode--;
}

void SLLL::InsertAtPos(int no, int pos)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if (pos < 1 || pos > (CountNode + 1))
    {
        cout << "Invalid position!\n";
        return;
    }

    else if (pos == 1)      // InsertFirst
    {
        InsertFirst(no);
    }

    else if (pos == CountNode + 1)      // InsertLast
    {
        InsertLast(no);
    }

    else        // Inserting at any random position
    {
        PNODE temp = Head;

        for (int i = 1; i < (pos - 1); i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        CountNode++;
    }
}

void SLLL::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > CountNode)
    {
        cout << "Invalid position!\n";
        return;
    }

    else if (pos == 1)      // DeleteFirst
    {
        DeleteFirst();      
    }

    else if (pos == CountNode)      // DeleteLast
    {
        DeleteLast();       
    }

    else        // Deleting at any random position
    {
        PNODE temp = Head;

        for (int i = 1; i < (pos - 1); i++)
        {
            temp = temp->next;
        }

        PNODE tempdelete = temp->next;
        temp->next = temp->next->next;
        delete tempdelete;

        CountNode--;
    }
}

void SLLL::Display()        // To display the LL
{
    PNODE temp = Head;
    
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

int SLLL::Count()       // To count number of nodes in LL
{
    return CountNode;
}

int main()
{
    SLLL obj;
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