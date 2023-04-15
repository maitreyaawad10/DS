#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// BRUTE FORCE APPROACH, TC : O(N), SC : O(1)
Node* sortList(Node *head)
{
    Node* temp = head;
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    while(temp != NULL){
        if(temp -> data == 0)
            zeroCount++;
        else if(temp -> data == 1)
            oneCount++;
        else
            twoCount++;  

        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL){
        if(zeroCount != 0){
            temp -> data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp -> data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp -> data = 2;
            twoCount++;
        }

        temp = temp -> next;
    }

    return head;
}


// OPTIMAL APPROACH, TC : O(N), SC : O(1)
void insertAtTail(Node* &tail, Node* &curr){
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while(curr != NULL){
        int value = curr -> data;

        if(value == 0){
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1){
            insertAtTail(oneTail, curr);
        }
        else{
            insertAtTail(twoTail, curr);
        }

        curr = curr -> next;
    }

    curr = head;

    if(oneHead -> next != NULL)
        zeroTail -> next = oneHead -> next;
    else
        zeroTail -> next = twoHead -> next;

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    head = zeroHead -> next;

    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);

    return head;
}