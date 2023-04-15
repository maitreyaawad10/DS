#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// BRUTE FORCE APPROACH, TC : O(N), SC : O(N)
ListNode* reverseList(ListNode* head) {
    vector<int> v;

    ListNode* temp = head;

    while(temp != NULL) {
        v.push_back(temp -> val);
        temp = temp -> next;
    }   

    ListNode* tempNew = head;

    int i = v.size() - 1;
    while(tempNew != NULL){
        tempNew -> val = v[i];
        tempNew = tempNew -> next;
        i--;
    }

    return head;
}

// USING ITERATION
// OPTIMAL APPROACH, TC : O(N), SC : O(1)
ListNode* reverseList(ListNode* head) {
    ListNode* currentNode = NULL;
    ListNode* previousNode = NULL;

    while(head != NULL){
        currentNode = head;
        head = head -> next;
        currentNode -> next = previousNode;
        previousNode = currentNode;
    }

    return currentNode;
}


// USING RECURSION
// OPTIMAL APPROACH, TC : O(N), SC : O(1)
ListNode* reverse(ListNode* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    ListNode* newHead = reverse(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return newHead;
}

ListNode* reverseList(ListNode* head) {
    return reverse(head);
}


// USING RECURSION
// OPTIMAL APPROACH, TC : O(N), SC : O(1)
ListNode* reverse(ListNode* head, ListNode* currentNode, ListNode* previousNode){
    if(head == NULL)
        return currentNode;

    currentNode = head;
    head = head -> next;
    currentNode -> next = previousNode;
    previousNode = currentNode;

    return reverse(head, currentNode, previousNode);
}

ListNode* reverseList(ListNode* head) {
    ListNode* currentNode = head;
    ListNode* previousNode = NULL;

    return reverse(head, currentNode, previousNode);
}
