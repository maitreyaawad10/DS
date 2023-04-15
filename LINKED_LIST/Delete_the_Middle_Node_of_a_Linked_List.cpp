#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* deleteMiddle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    if(head -> next == NULL){
        head = head -> next;
    }

    else if(head -> next -> next == NULL){
        head -> next = NULL;
    }

    else{
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        slow -> val = slow -> next -> val;
        slow -> next = slow -> next -> next;
    }

    return head;
}