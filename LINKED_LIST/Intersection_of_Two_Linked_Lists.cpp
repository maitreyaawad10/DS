#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// BRUTE FORCE, TC : O(N1 * N2), SC : O(1)
ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
    while(head2 != NULL) {
        ListNode* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}

// BETTER APPROACH, TC : O(N1 + N2), SC : O(N1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* l1 = headA;
    ListNode* l2 = headB;

    unordered_set<ListNode*> st;

    while(l1 != NULL){
        st.insert(l1);
        l1 = l1 -> next;
    }

    while(l2 != NULL){
        if(st.find(l2) != st.end())
            return l2;

        l2 = l2 -> next;
    }

    return NULL;
}

// OPTIMAL APPROACH, TC : O(N1 + N2), SC : O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* l1 = headA;
    ListNode* l2 = headB;

    if(l1 == NULL || l2 == NULL)
        return NULL;

    while(l1 != l2){
        l1 = l1 == NULL ? headB : l1 -> next;
        l2 = l2 == NULL ? headA : l2 -> next;
    }

    return l1;
}

