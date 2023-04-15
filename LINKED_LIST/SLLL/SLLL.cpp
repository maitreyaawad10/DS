#include <bits/stdc++.h>

using namespace std;

class SLLL {
    private:
        struct Node {
            int data;
            struct Node* next;
        };

        struct Node* Head;
        int NodeCount;

    public:
        SLLL();

        void InsertFirst(int value);
        void DeleteFirst();
        
        void InsertLast(int value);
        void DeleteLast();

        void InsertAtPos(int value, int pos);
        void DeleteAtPos(int pos);

        void Display();
        int CountNode();
};


SLLL::SLLL(){
    Head = NULL;
    NodeCount = 0;
}

void SLLL::InsertFirst(int value){
    struct Node* newn = new Node;
    
    newn -> data = value;
    newn -> next = NULL;

    if(Head == NULL){
        Head = newn;
    }
    else{
        newn -> next = Head;
        Head = newn;
    }

    NodeCount++;
}

void SLLL::DeleteFirst(){
    if(Head == NULL)
        return;

    struct Node* delNode = Head;
    Head = Head -> next;
    delete(delNode);

    NodeCount--;
}


void SLLL::InsertLast(int value){
    struct Node* newn = new Node;
    
    newn -> data = value;
    newn -> next = NULL;

    if(Head == NULL){
        Head = newn;
    }
    else{
        struct Node* temp = Head;

        while(temp -> next != NULL){
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    NodeCount++;
}

void SLLL::DeleteLast(){
    if(Head == NULL)
        return;

    if(Head -> next == NULL){   // IF LL HAS ONLY 1 NODE
        delete(Head);
        Head = NULL;
    }
    else{
        struct Node* temp = Head;

        while(temp -> next -> next != NULL){
            temp = temp -> next;
        }

        delete(temp -> next);
        temp -> next = NULL;
    }

    NodeCount--;
}

void SLLL::InsertAtPos(int value, int pos){
    if(pos == 1){
        InsertFirst(value);
        return;
    }

    if(pos == NodeCount + 1){
        InsertLast(value);
        return;
    }

    if(pos < 1 || pos > NodeCount + 1){
        cout << "Invalid position!\n";
        return;
    }

    struct Node* newn = new Node;

    newn -> data = value;
    newn -> next = NULL;

    struct Node* temp = Head;

    for(int i = 1; i < pos - 1; ++i){
        temp = temp -> next;
    }

    newn -> next = temp -> next;
    temp -> next = newn;

    NodeCount++;
}

void SLLL::DeleteAtPos(int pos){
    if(pos == 1){
        DeleteFirst();
        return;
    }

    if(pos == NodeCount){
        DeleteLast();
        return;
    }

    if(pos < 1 || pos > NodeCount){
        cout << "Invalid position!\n";
        return;
    }

    struct Node* temp = Head;
    struct Node* tempDel = NULL;

    for(int i = 1; i < pos - 1; ++i){
        temp = temp -> next;
    }

    tempDel = temp -> next;
    temp -> next = temp -> next -> next;
    delete(tempDel);

    NodeCount--;
}

void SLLL::Display(){
    struct Node* temp = Head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int SLLL::CountNode(){    
    return NodeCount;
}


int main(){
    SLLL obj;

    obj.InsertFirst(8);
    obj.InsertFirst(9);
    obj.InsertFirst(10);
    obj.Display();
    cout << "No. of nodes are : " << obj.CountNode() << endl;
    
    obj.InsertLast(5);
    obj.InsertLast(6);
    obj.InsertLast(7);
    obj.Display();
    cout << "No. of nodes are : " << obj.CountNode() << endl;

    // obj.DeleteFirst();
    // obj.Display();
    // cout << "No. of nodes are : " << obj.CountNode() << endl;

    // obj.DeleteLast();
    // obj.Display();
    // cout << "No. of nodes are : " << obj.CountNode() << endl;

    obj.InsertAtPos(100, 3);
    obj.Display();
    cout << "No. of nodes are : " << obj.CountNode() << endl;

    obj.DeleteAtPos(2);
    obj.Display();
    cout << "No. of nodes are : " << obj.CountNode() << endl;

    return 0;
}
