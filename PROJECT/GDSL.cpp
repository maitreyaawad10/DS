template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLLL
{
private:
    struct node<T> *Head;
    int Countnode;

public:
    SinglyLLL();

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
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyLLL
{
private:
    struct node<T> *Head;
    int CountNode;

public:
    DoublyLLL();

    void InsertFirst(T);
    void InsertLast(T);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T, int);
    void DeleteAtPos(int);

    void Display();
    int Count();
};

/////////////////////////////
// SINGLY LINEAR 
/////////////////////////////

template <class T>
SinglyLLL<T>::SinglyLLL()
{
    Head = NULL;
    Countnode = 0;
}

template <class T>
void SinglyLLL<T>::InsertFirst(T value)
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
void SinglyLLL<T>::InsertLast(T value)
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
void SinglyLLL<T>::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }

    else
    {
        struct node<T>  *temp = Head;

        Head = Head->next;
        delete temp;
    }

    Countnode--;
}

template <class T>
void SinglyLLL<T>::DeleteLast()
{
    if (Head == NULL)
    {
        return;
    }

    else if (Countnode == 1)
    {
        delete Head;
        Head = NULL;
    }

    else
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
void SinglyLLL<T>::InsertAtPos(T value, int pos)
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

    else if (pos == 1)
    {
        InsertFirst(value);
    }

    else if (pos == Countnode + 1)
    {
        InsertLast(value);
    }

    else
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
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > Countnode)
    {
        cout << "Invalid position!\n";
        return;
    }

    else if (pos == 1)
    {
        DeleteFirst();
    }

    else if (pos == Countnode)
    {
        DeleteLast();
    }

    else
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
void SinglyLLL<T>::Display()
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
int SinglyLLL<T>::Count()
{
    return Countnode;
}

/////////////////////////////
// DOUBLY LINEAR 
/////////////////////////////

template <class T>
DoublyLLL<T>::DoublyLLL()
{
    Head = NULL;
    CountNode = 0;
}

template <class T>
void DoublyLLL<T>::InsertFirst(T value)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

    newn -> data = no;
    newn -> prev = NULL;
    newn -> next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }

    else
    {
        newn -> next = Head;
        Head -> prev = newn;
        Head = newn;
    }

    CountNode++;
}

template <class T>
void DoublyLLL<T>::InsertLast(T value)
{
    struct node<T>*newn = NULL;

    newn = new node<T>;

    newn -> data = no;
    newn -> prev = NULL;
    newn -> next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }

    else if(Head -> next == NULL && Head -> prev == NULL)
    {
        Head -> next = newn;
        newn -> prev = Head;
    }

    else
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
void DoublyLLL<T>::DeleteFirst()
{
    if(Head == NULL)
    {
        return;
    }

    else if(Head -> next == NULL && Head -> prev == NULL)
    {
        delete Head;
        Head = NULL;
    }

    else
    {
        Head = Head -> next;
        delete Head -> prev;
        Head -> prev = NULL;
    }

    CountNode--;
}

template <class T>
void DoublyLLL<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }

    else if(Head -> next == NULL && Head -> prev == NULL)
    {
        delete Head;
        Head = NULL;
    }

    else
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
void DoublyLLL<T>::InsertAtPos(T value, int pos)
{
    if(pos < 1 || pos > (CountNode+1))
    {
        cout << "Inavlid position!\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(value);
    }

    else if(pos == CountNode+1)
    {
        InsertLast(value);
    }

    else
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
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > CountNode)
    {
        cout << "Inavlid position!\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }

    else if(pos == CountNode)
    {
        DeleteLast();
    }

    else
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
void DoublyLLL<T>::Display()
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
int DoublyLLL<T>::Count()
{
    return CountNode;
}