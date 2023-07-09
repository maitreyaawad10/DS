#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

// LINKED LIST INSERT FIRST FUNCTION
void push(struct Node **head, int data){
    struct Node *newn = new Node;

    newn -> data = data;
    newn -> next = NULL;
    
    if(*head == NULL){
        *head = newn;
    }
    else{
        newn -> next = *head;
        *head = newn;
    }
}

// LINKED LIST DELETE FIRST FUNCTION
int pop(struct Node **head){
    int val = ((*head) -> data);

    if(*head == NULL){
        cout << "STACK IS EMPTY!\n";
    }

    else if(((*head) -> next) == NULL){
        delete(*head);
        *head = NULL;
    }

    else{
        struct Node *temp = *head;

        (*head) = (*head) -> next;

        delete(temp);
    }

    return val;
}

// TO CHECK IF STACK IS EMPTY
bool isEmpty(struct Node **head){
    if(*head == NULL)
        return true;
    
    return false;
}

// TO DISPLAY THE CONTENTS OF STACK
void display(struct Node *head){
    struct Node *temp = head;

    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }

    cout << "NULL\n";
}

int main(){
    struct Node *first = NULL;

    push(&first, 30);
    push(&first, 40);
    push(&first, 50);
    push(&first, 20);
    push(&first, 10);
    display(first);
    first == NULL ? cout << "TOP OF STACK IS : " << "NULL" : cout << "TOP OF STACK IS : " << first -> data;
    cout << endl;

    int top = pop(&first);
    cout << "POPPED ELEMENT IS : " << top << endl;
    display(first);
    first == NULL ? cout << "TOP OF STACK IS : " << "NULL" : cout << "TOP OF STACK IS : " << first -> data;

    cout << endl;

    return 0;
}