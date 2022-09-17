#include <iostream>

using namespace std;

template <class T>
struct node
{
    T data;
    struct node* next;
    struct node* prev;
};

template <class T>
class DCLL
{
    private :
        struct node<T>* Head;
        struct node<T>* Tail;
        int Count;

    public :
        DCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int CountNode();
};

template <class T>
DCLL<T>::DCLL()     // Constructor
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template <class T>
void DCLL<T>::InsertFirst(T value)
{
    struct node<T>* newn = new node<T>;

    newn -> data = value;
    newn -> next = NULL;
    newn -> prev = NULL;
    
    if(Head == NULL && Tail == NULL)        // If LL is empty   
    {
        Head = newn;
        Tail = newn;
    }

    else         // If LL contains atleast 1 element
    {
        newn -> next = Head;
        Head -> prev = newn;
        Head = newn;
    }

    Head -> prev = Tail;
    Tail -> next = newn;

    Count++;
}

template <class T>
void DCLL<T>::InsertLast(T value)
{
    struct node<T>* newn = new node<T>;

    newn -> data = value;
    newn -> next = NULL;
    newn -> prev = NULL;
    
    if(Head == NULL && Tail == NULL)        // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }

    else         // If LL contains atleast 1 element
    {
        Tail -> next = newn;
        newn -> prev = Tail;
        Tail = newn;
    }

    Tail -> next = Head;
    Head -> prev = Tail;

    Count++;
}

template <class T>
void DCLL<T>::DeleteFirst()
{
    if(Head == NULL && Tail == NULL)        // If LL is empty
    {
        return;
    }

    else         // If LL contains atleast 1 element
    {
        Head = Head -> next;
        delete Tail -> next;
        
    }

    Tail -> next = Head;
    Head -> prev = Tail;
    
    Count--;
}

template <class T>
void DCLL<T>::DeleteLast()
{
    if(Head == NULL && Tail == NULL)        // If LL is empty
    {
        return;
    }

    else         // If LL contains atleast 1 element
    {
        Tail = Tail -> prev;
        delete Tail -> next;
    }

    Tail -> next = Head;
    Head -> prev = Tail;
    
    Count--;
}

template <class T>
void DCLL<T>::InsertAtPos(T value, int pos)
{
    if(pos < 1 || pos > Count+1)
    {
        cout << "Invalid position!\n";
    	return;
    }

    if(pos == 1)        // InsertFirst
    {
    	InsertFirst(value);
    }
    
    else if(pos == (Count + 1))     // InsertLast
    {
    	InsertLast(value);
    }

    else            // Inserting at any random position
    {
        struct node<T>* newn = new node<T>;

        newn -> data = value;
        newn -> next = NULL;
        newn -> prev = NULL; 

        struct node<T>* temp = Head;

        for(int i = 1; i < (pos - 1); i++)
    	{
    		temp = temp -> next;
    	}

        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;

        Count++;
    }
}

template <class T>
void DCLL<T>::DeleteAtPos(int pos)
{
    if((pos < 1) || (pos > Count))
    {
    	cout << "Invalid position!\n";
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

    else             // Deleting any random position node
    {
        struct node<T>* temp = Head;
    	
    	for(int i = 1; i < (pos - 1); i++)
    	{
    		temp = temp -> next;
    	}

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        Count--;
    }
}

template <class T>
void DCLL<T>::Display()         // To display the LL
{
    struct node<T>* temp = Head;
    
    for(int i = 1; i <= Count; i++)
    {
    	cout << "| " << temp -> data << " | <=> ";
    	temp = temp -> next;
    }
    
    cout << "NULL\n";
}

template <class T>
int DCLL<T>::CountNode()         // To count number of nodes in LL
{
    return Count;
}

int main(){
    DCLL <int> obj;
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