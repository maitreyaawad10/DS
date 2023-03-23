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

// OPTIMAL APPROACH, TC : O(N), SC : O(1)
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* next = head;

    while(head != NULL){
        next = head -> next;
        head -> next = prev;
        prev = head;
        head = next;
    }

    return prev;
}