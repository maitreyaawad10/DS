#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// BRUTE FORCE APPROACH, TC : O(N), SC : O(1)
int CountNode(ListNode* head){
    if(head == NULL)
        return 0;

    ListNode* temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp -> next;
    }

    return count;
}

ListNode* middleNode(ListNode* head) {
    int count = CountNode(head);

    int middle = (count / 2) + 1;

    ListNode* temp = head;
    for(int i = 1; i < middle; ++i)
        temp = temp -> next;

    return temp;
}

// OPTIMAL APPROACH, TC : O(N), SC : O(1)
// TORTOISE METHOD, FAST AND SLOW POINTERS
ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}