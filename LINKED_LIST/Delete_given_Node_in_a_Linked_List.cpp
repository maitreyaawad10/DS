#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// OPTIMAL APPRAOCH, TC : O(1), SC : O(1)
void deleteNode(ListNode* node) {
    node -> val = node -> next -> val;
    node -> next = node -> next -> next;
    // WE'RE INDIRECTLY DELETING THE NEXT NODE OF GIVEN NODE AND STORING IT'S VALUE INTO GIVEN NODE AND POINTING IT TO NEXT OF THE GIVEN NODE'S NEXT.
}