#include <bits/stdc++.h>

using namespace std;

class Node {
    public :

    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};  


// OPTIMAL APPROACH, TC : O(N), SC : O(1)
Node *loopNode(Node *head)
{
	if(head == NULL || head -> next == NULL)
		return NULL;

	Node* fast = head;
	Node* slow = head;
	Node* entry = head;

	while(fast -> next != NULL && fast -> next -> next != NULL){
		fast = fast -> next -> next;
		slow = slow -> next;

		if(fast == slow){
			while(slow != entry){
				slow = slow -> next;
				entry = entry -> next;
			}

			return entry;
		}
	}

	return NULL;
}

Node *removeLoop(Node *head)
{
    Node* loopStartNode = loopNode(head);
    if(loopStartNode == NULL)
        return head;

    Node* curr = loopStartNode;

    while(curr -> next != loopStartNode)
        curr = curr -> next;
    
    curr -> next = NULL;
    return head;
}


