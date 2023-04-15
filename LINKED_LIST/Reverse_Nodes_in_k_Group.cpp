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
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || k == 1)
        return head;

    ListNode* dummy = new ListNode();
    dummy -> next = head;

    ListNode* temp = dummy;
    int len = 0;

    while(temp -> next != NULL){
        temp = temp -> next;
        len++;
    }

    ListNode* prev = dummy;
    ListNode* curr = dummy;
    ListNode* next1 = dummy;

    while(len >= k){
        curr = prev -> next;
        next1 = curr -> next;

        for(int i = 1; i < k; ++i){
            curr -> next = next1 -> next;
            next1 -> next = prev -> next;
            prev -> next = next1;
            next1 = curr -> next;
        }

        prev = curr;
        len -= k;
    }

    return dummy -> next;
}
