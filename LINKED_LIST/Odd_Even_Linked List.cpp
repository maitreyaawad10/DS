#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};


// OPTIMAL APPROACH, TC : O(N), SC : O(1)
void insertAtTail(Node* &newn, Node* &tail){
    tail -> next = newn;
    tail = newn;
}

Node* divide(int N, Node *head){
    Node* odd = new Node(0);
    Node* oddTail = odd;

    Node* even = new Node(0);
    Node* evenTail = even;

    Node* curr = head;

    while(curr != NULL){
        if((curr -> val) % 2 != 0){
            insertAtTail(curr, oddTail); 
        }
        else{
            insertAtTail(curr, evenTail);
        }

        curr = curr -> next;
    }

    oddTail -> next = NULL;
    evenTail -> next = NULL;

    evenTail -> next = odd -> next;

    return even -> next;
}