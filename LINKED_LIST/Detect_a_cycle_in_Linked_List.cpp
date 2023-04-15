#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// BRUTE FORCE, TC : O(N), SC : O(N)
bool hasCycle(ListNode *head) {
    ListNode* l1 = head;

    unordered_set<ListNode*> st;

    while(l1 != NULL){
        if(st.find(l1) != st.end())
            return true;

        st.insert(l1);
        l1 = l1 -> next;
    }

    return false;
}

// OPTIMAL APPROACH, TC : O(N), SC : O(1)
bool hasCycle(ListNode *head) {
    if(head == NULL || head -> next == NULL)
        return false;

    ListNode* fast = head;
    ListNode* slow = head;

    while(fast -> next != NULL && fast -> next -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == slow)
            return true;
    }

    return false;
}


