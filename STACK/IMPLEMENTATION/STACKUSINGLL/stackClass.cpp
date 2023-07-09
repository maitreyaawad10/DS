#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

class Stack{
    private:
        struct Node *head;
        int stackSize;

    public:
        Stack();

        void push(int data);
        int pop();
        bool isEmpty();
        void display();
        int size();
};

Stack::Stack(){
    head = NULL;
    stackSize = 0;
}

// LINKED LIST INSERT FIRST FUNCTION
void Stack::push(int data){
    struct Node *newn = new Node;

    newn -> data = data;
    newn -> next = NULL;
    
    if(head == NULL){
        head = newn;
    }
    else{
        newn -> next = head;
        head = newn;
    }

    stackSize++;
}

// LINKED LIST DELETE FIRST FUNCTION
int Stack::pop(){
    int val = head -> data;

    if(head == NULL){
        cout << "STACK IS EMPTY!\n";
    }

    else if(((head) -> next) == NULL){
        delete(head);
        head = NULL;
        stackSize--;
    }

    else{
        struct Node *temp = head;

        (head) = (head) -> next;

        delete(temp);
        stackSize--;
    }

    return val;
}

// TO CHECK IF STACK IS EMPTY
bool Stack::isEmpty(){
    if(head == NULL)
        return true;
    
    return false;
}

// TO DISPLAY THE CONTENTS OF STACK
void Stack::display(){
    struct Node *temp = head;

    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }

    cout << "NULL\n";
}

int Stack::size(){
    return stackSize;
}

int main(){
    Stack stack;

    cout << stack.isEmpty() << endl;
    stack.display();
    cout << stack.size() << endl;
    
    stack.push(25);
    stack.push(35);
    stack.push(55);

    cout << stack.isEmpty() << endl;
    stack.display();
    cout << stack.size() << endl;

    stack.pop();
    cout << stack.isEmpty() << endl;
    stack.display();
    cout << stack.size() << endl;

    return 0;
}