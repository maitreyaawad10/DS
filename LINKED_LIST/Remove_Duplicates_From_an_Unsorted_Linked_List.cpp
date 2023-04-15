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

// OPTIMAL APPROACH, TC : O(N), SC : O(N)
Node *removeDuplicates(Node *head)
{
    Node* prev = NULL;
    Node* curr = head;
    
    unordered_map<int, int> mp;

    while(curr != NULL){
        if(mp.find(curr -> data) != mp.end()){
            prev -> next = prev -> next -> next;
        }
        else{
            mp[curr -> data] = 1;
            prev = curr;
        }
        
        curr = curr -> next;  
    }

    return head;
}