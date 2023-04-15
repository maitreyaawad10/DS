#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// OPTIMAL APPROACH, TC : O(NLOG(N)), SC : O(LOG(N))
ListNode* merge(ListNode* left, ListNode* right){
    if(right == NULL)
        return left;

    if(left == NULL)
        return right;

    ListNode* ans = new ListNode();
    ListNode* curr = ans;

    while(left != NULL && right != NULL){
        if(left -> val <= right -> val){
            curr -> next = left;
            curr = left;
            left = left -> next;
        }
        else{
            curr -> next = right;
            curr = right;
            right = right -> next;
        }
    }

    while(left != NULL){
        curr -> next = left;
        curr = left;
        left = left -> next;
    }

    while(right != NULL){
        curr -> next = right;
        curr = right;
        right = right -> next;
    }

    return ans -> next;
}

ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast -> next != NULL && fast -> next -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

ListNode* sortList(ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;

    ListNode* left = head;
    ListNode* mid = findMiddle(head);
    ListNode* right = mid -> next;
    mid -> next = NULL;

    left = sortList(left);
    right = sortList(right);
    head = merge(left, right);

    return head;
}