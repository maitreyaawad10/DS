#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// BRUTE FORCE APPROACH, TC : O(2N), SC : O(1), DOUBLE TRAVERSAL OF LL
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp = head;
    int len = 0;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }

    int pos = len - n + 1;

    temp = head;
    for(int i = 1; i < pos - 1; ++i)
        temp = temp -> next;

    ListNode* tempdel = temp -> next;

    if(pos == 1){
        tempdel = head;
        head = head -> next;
        delete(tempdel);
    }
    else{
        temp -> next = temp -> next -> next;
        delete(tempdel);
    }

    return head;
}

// OPTIMAL APPRAOCH, TC : O(N), SC : O(1), SINGLE TRAVERSAL
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(n == 0 || head == NULL)
        return head;
        
    ListNode* dummyNode = new ListNode();
    dummyNode -> next = head;

    ListNode* fast = dummyNode;
    ListNode* slow = dummyNode;

    for(int i = 1; i <= n; ++i)
        fast = fast -> next;

    while(fast -> next != NULL){
        fast = fast -> next;
        slow = slow -> next;
    }

    ListNode* delNode = slow -> next;
    slow -> next = slow -> next -> next;
    delete(delNode);

    return dummyNode -> next;
}