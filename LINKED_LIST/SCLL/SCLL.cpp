#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node* next;
}NODE, * PNODE;

class SCLL
{
    private :
        PNODE Head;
        PNODE Tail;
        int Count;

    public :
        SCLL();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int CountNode();
};

SCLL::SCLL()        // Constructor
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

void SCLL::InsertFirst(int value)
{
    PNODE newn = new NODE;

    newn -> data = value;
    newn -> next = NULL;
    
    if(Head == NULL && Tail == NULL)    // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }

    else        // If LL contains atleast 1 element
    {
        newn -> next = Head;
        Head = newn;
    }

    Tail -> next = Head;

    Count++;
}

void SCLL::InsertLast(int value)
{
    PNODE newn = new NODE;

    newn -> data = value;
    newn -> next = NULL;
    
    if(Head == NULL && Tail == NULL)    // If LL is empty
    {
        Head = newn;
        Tail = newn;   
    }

    else           // If LL contains atleast 1 element
    {
        Tail -> next = newn;
        Tail = newn;
    }

    Tail -> next = Head;

    Count++;
}

void SCLL::DeleteFirst()
{
    if(Head == NULL && Tail == NULL)    // If LL is empty
    {
        return; 
    }

    else if(Head == Tail)       // If LL contains only 1 element
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }

    else           // If LL contains more than 1 element
    {
        Head = Head -> next;
        delete Tail -> next;
        Tail -> next = Head;
    }

    Count--;
}

void SCLL::DeleteLast()
{
    if(Head == NULL && Tail == NULL)    // If LL is empty
    {
        return; 
    }

    else if(Head == Tail)       // If LL contains only 1 element
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }

    else            // If LL contains more than 1 element
    {
        PNODE temp = Head;

        while(temp -> next != Tail)
        {
            temp = temp -> next;
        }
        
        delete Tail;
        Tail = temp;
        Tail -> next = Head;
    }

    Count--;
}

void SCLL::InsertAtPos(int value, int pos)
{
    if(pos < 1 || pos > Count+1)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    if(pos == 1)        // InsertFirst
    {
        InsertFirst(value);
    }

    else if(pos == Count+1)     // InsertLast
    {
        InsertLast(value);
    }

    else        // Inserting at any random position
    {
        PNODE newn = new NODE;

        newn -> data = value;
        newn -> next = NULL;

        PNODE temp = Head;

        for(int i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        Count++;
    }
}

void SCLL::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > Count)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    if(pos == 1)        // DeleteFirst
    {
        DeleteFirst();
    }

    else if(pos == Count)       // DeleteLast
    {
        DeleteLast();
    }

    else            // Deleting any random position node
    {
        PNODE temp = Head;

        for(int i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        PNODE tempdel = temp -> next;
        temp -> next = temp -> next -> next;
        delete tempdel;

        Count--;
    }
}

void SCLL::Display()         // To display the LL
{
    PNODE temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }

    cout << "Elements of linked list are :\n";

    do
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp -> next;
    } 
    while (temp != Head);

    cout << "NULL\n";
    
}

int SCLL::CountNode()       // To count number of nodes in LL
{
    return Count;
}

int main(){
    SCLL obj;
    int choice = 1, pos = 0, value = 0;

    while(choice != 0)
    {
        cout << "Choose from following options : " << endl;
    	
    	cout << "1 : InsertFirst" << endl;
    	cout << "2 : InsertLast" << endl;
    	cout << "3 : InsertAtPosition" << endl;
    	cout << "4 : DeleteFirst" << endl;
    	cout << "5 : DeleteLast" << endl;
    	cout << "6 : DeleteAtPosition" << endl;
    	cout << "7 : Display the Linked list" << endl;
    	cout << "8 : Count the number of nodes of Linked list" << endl;
    	cout << "9 : Exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1 :
                cout << "Enter the value you want to insert : ";
                cin >> value;
                obj.InsertFirst(value);
                cout << "Node inserted successfully." << endl;
                cout << "-----------------------------------------------------------------------------------\n";
                break;

            case 2 :
                cout << "Enter the value you want to insert : ";
                cin >> value;
                obj.InsertLast(value);
                cout << "Node inserted successfully." << endl;
                cout << "-----------------------------------------------------------------------------------\n";
                break;

            case 3 :
                cout << "Enter the value you want to insert : ";
                cin >> value;
                cout << "Enter the position : ";
                cin >> pos;
                obj.InsertAtPos(value, pos);
                if(pos >= 1 && pos <= obj.CountNode()+1)
                {
                    cout << "Node inserted successfully." << endl;
                }
                cout << "-----------------------------------------------------------------------------------\n";
                break;

            case 4 :
                if(obj.CountNode() >= 1)
                {
                    cout << "Node deleted successfully." << endl;
                }
                obj.DeleteFirst();
                cout << "-----------------------------------------------------------------------------------\n";
                break;

            case 5 :
                if(obj.CountNode() >= 1)
                {
                    cout << "Node deleted successfully." << endl;
                }
                obj.DeleteLast();
                cout << "-----------------------------------------------------------------------------------\n";
                break;

            case 6 :
                cout << "Enter the position : ";
                cin >> pos;
                if(pos >= 1 && pos <= obj.CountNode())
                {
                    cout << "Node deleted successfully." << endl;
                }
                obj.DeleteAtPos(pos);
                cout << "-----------------------------------------------------------------------------------\n";
                break;

            case 7 :
                cout << "-----------------------------------------------------------------------------------\n";
                obj.Display();
                cout << "-----------------------------------------------------------------------------------\n";
                break;

            case 8 :
                cout << "-----------------------------------------------------------------------------------\n";
                cout << "Number of nodes in linked list are : " << obj.CountNode() << endl;
                cout << "-----------------------------------------------------------------------------------\n";
                break;

            case 9 :
                cout << "-----------------------------------------------------------------------------------\n";
                cout << "Thank you for using this application!" << endl;
                cout << "-----------------------------------------------------------------------------------\n";
                choice = 0;
                break;

            default :
                cout << "Invalid choice!" << endl;
                cout << "-----------------------------------------------------------------------------------\n";
                break;
        }
    }

    return 0;
}