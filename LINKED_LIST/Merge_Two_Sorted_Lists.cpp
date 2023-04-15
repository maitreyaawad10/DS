#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// BRUTE FORCE APPROACH, TC : O(N1 + N2), SC : O(N1 + N2)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* newHead = new ListNode;
    ListNode* tempNode = newHead;

    ListNode* temp1 = list1;
    ListNode* temp2 = list2;

    while(temp1 != NULL && temp2 != NULL){
        if((temp1 -> val) < (temp2 -> val)){
            ListNode* newn = new ListNode(temp1 -> val);
            tempNode -> next = newn;
            temp1 = temp1 -> next;
            tempNode = tempNode -> next;
        }
        else{
            ListNode* newn = new ListNode(temp2 -> val);
            tempNode -> next = newn;
            temp2 = temp2 -> next;
            tempNode = tempNode -> next;
        }
    }

    while(temp1 != NULL){
        ListNode* newn = new ListNode(temp1 -> val);
        tempNode -> next = newn;
        temp1 = temp1 -> next;
        tempNode = tempNode -> next;
    }

    while(temp2 != NULL){
        ListNode* newn = new ListNode(temp2 -> val);
        tempNode -> next = newn;
        temp2 = temp2 -> next;
        tempNode = tempNode -> next;
    }

    return newHead -> next;
}

// OPTIMAL APPROACH, TC : O(N1 + N2), SC : O(1)
ListNode* solve(ListNode* left, ListNode* right){
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;

    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while(left != NULL && right != NULL){
        if(left -> val <= right -> val){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    if(left != NULL)
		temp -> next = left;
        
	else
		temp -> next = right;

    dummyNode = dummyNode -> next;

    return dummyNode;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL)
        return list2;

    if(list2 == NULL)
        return list1;

    // CHECKING IF 1ST ELEMENT OF L1 IS <= FIRST ELEMENT OF L2
    if((list1 -> val) <= (list2 -> val))
        return solve(list1, list2);
    else
        return solve(list2, list1);
}

// OPTIMAL APPROACH, TC : O(N1 + N2), SC : O(1)
ListNode* solve(ListNode* list1, ListNode* list2){
    if(list1 -> next == NULL){
        list1 -> next = list2;
        return list1;
    }

    ListNode* prev = list1;
    ListNode* next1 = list1 -> next;
    ListNode* curr = list2;

    while(next1 != NULL && curr != NULL){
        if(((curr -> val) >= (prev -> val)) && ((curr -> val) <= (next1 -> val))){
            ListNode* temp = curr -> next;
            prev -> next = curr;
            curr -> next = next1;
            prev = curr;
            // next1 = prev -> next;
            curr = temp; 
        }

        else{
            prev = next1;
            next1 = next1 -> next;

            if(next1 == NULL){
                prev -> next = curr;
                return list1;
            }
        }
    }

    return list1;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL)
        return list2;

    if(list2 == NULL)
        return list1;

    // CHECKING IF 1ST ELEMENT OF L1 IS <= FIRST ELEMENT OF L2
    if((list1 -> val) <= (list2 -> val))
        return solve(list1, list2);
    else
        return solve(list2, list1);
}