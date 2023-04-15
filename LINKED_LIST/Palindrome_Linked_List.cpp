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
bool isPalindrome(ListNode* head) {
    ListNode* temp = head;

    vector<int> v;

    while(temp != NULL){
        v.push_back(temp -> val);
        temp = temp -> next;
    }

    int i = 0, j = v.size() - 1;

    while(i <= j){
        if(v[i] == v[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }

    return true;
}


// OPTIMAL APPROACH, TC : O(N), SC : O(1)
ListNode* reverse(ListNode* head){
    if(head == NULL || head -> next == NULL)
        return head;

    ListNode* newHead = reverse(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return newHead;
}

bool isPalindrome(ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return true;
    
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast -> next != NULL && fast -> next -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    slow = slow -> next;
    // reverse the other half of LL to check for pallindrome
    slow = reverse(slow);
    
    ListNode* start = head;

    while(slow != NULL){
        if(slow -> val != start -> val)
            return false;

        slow = slow -> next;
        start = start -> next;
    }

    return true;
}