#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// OPTIMAL APPROACH, TC : O(MAX(N1, N2)), SC : O(MAX(N1, N2))
// IF NUMBERS ARE REPRESENTED IN REVERSE ORDER
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* newHead = new ListNode();
    ListNode* curr = newHead;

    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry){
        int sum = 0;

        if(l1 != NULL){
            sum += (l1 -> val);
            l1 = l1 -> next;
        }

        if(l2 != NULL){
            sum += (l2 -> val);
            l2 = l2 -> next;
        }

        sum += carry;
        carry = sum / 10;

        ListNode* newn = new ListNode();
        newn -> val = sum % 10;
        curr -> next = newn; 
        curr = newn;   
    }

    return newHead -> next;
}

// IF NUMBERS ARE NOT REPRESENTED IN REVERSE ORDER
ListNode* reverse(ListNode* head){
    if(head -> next == NULL){
        return head;
    }
    
    ListNode* newHead = reverse(head -> next);
    
    head -> next -> next = head;
    head -> next = NULL;
    
    return newHead;
}

ListNode* addTwoLists(ListNode* first, ListNode* second)
{
    ListNode* dummy = new ListNode(-2);
    ListNode* curr = dummy;
    
    ListNode* list1 = reverse(first);
    ListNode* list2 = reverse(second);
    
    int carry = 0;
    
    while(list1 != NULL || list2 != NULL || carry){
        int sum = 0;
        
        if(list1 != NULL){
            sum += (list1 -> val);
            list1 = list1 -> next;
        }
        
        if(list2 != NULL){
            sum += (list2 -> val);
            list2 = list2 -> next;
        }
        
        sum += carry;
        
        carry = sum / 10;
        
        ListNode* newn = new ListNode(sum % 10);
        curr -> next = newn;
        curr = newn;
    }
    
    ListNode* head = reverse(dummy -> next);
    
    delete(dummy);
    
    return head;
}