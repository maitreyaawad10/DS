#include <bits/stdc++.h> 

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// BRUTE FORCE, TC : O(N), SC : O(N)
Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> mp;
    Node* curr = head;

    while(curr != NULL){
        Node* newn = new Node(curr -> val);
        mp[curr] = newn;
        curr = curr -> next;
    }

    curr = head;

    while(curr != NULL) {
        Node* node = mp[curr];
        node -> next = (curr -> next != NULL) ? mp[curr -> next]:NULL;
        node -> random = (curr -> random != NULL) ? mp[curr -> random]:NULL;
        curr = curr -> next;
    }   

    return mp[head];
}

// OPTIMAL APPROACH, TC : O(N), SC : O(1)
Node* copyRandomList(Node* head) {
    if(head == NULL)
        return NULL;

    Node* curr = head;

    // STEP 1 : INSERTING NEW NODES IN BETWEEN ORIGINAL NODES
    while(curr != NULL){
        Node* newn = new Node(curr -> val);
        newn -> next = curr ->  next;
        curr -> next = newn;
        curr = curr -> next -> next;
    }

    curr = head;

    // STEP 2 : DEFINING RANDOM POINTERS OF CLONED NODES
    while(curr != NULL){
        if(curr -> random != NULL)
            curr -> next -> random = curr -> random -> next;

        curr = curr -> next -> next;
    }

    Node* cloneHead = head -> next;
    Node* temp = cloneHead;

    curr = head;

    // STEP 3 : REVERTING THE CHANGES MADE TO ORIGINAL LIST
    // CHANGING THE NEXT POINTERS OF ORIGINAL AND CLONED LISTS
    while(curr != NULL && temp != NULL){
        curr -> next = temp -> next;
        curr = curr -> next;
        
        if(curr != NULL)
            temp -> next = curr -> next;
        else
            temp -> next = NULL;
            
        temp = temp -> next;
    }

    // STEP 4 : RETURNING HEAD OF CLONED LIST
    return cloneHead;
}