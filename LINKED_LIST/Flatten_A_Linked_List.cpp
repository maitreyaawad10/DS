#include <bits/stdc++.h>

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

// OPTIMAL APPROACH. TC: O(sum of all nodes), SC : O(1)
Node* mergeTwoLists(Node* left, Node* right){
	if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;

    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(left != NULL && right != NULL){
        if(left -> data <= right -> data){
            temp -> child = left;
            temp = left;
            left = left -> child;
        }
        else{
            temp -> child = right;
            temp = right;
            right = right -> child;
        }
    }

	if(left != NULL)
		temp -> child = left;
	else
		temp -> child = right;

    dummyNode = dummyNode -> child;

    return dummyNode;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head -> next == NULL)
		return head;

	Node* newHead = flattenLinkedList(head -> next);

	newHead = mergeTwoLists(head, newHead);
	newHead -> next = NULL;

	return newHead;
}
