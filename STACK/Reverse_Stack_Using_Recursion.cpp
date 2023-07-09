#include <bits/stdc++.h> 

using namespace std;

void insertAtBottom(stack<int>& myStack, int x){
    // BASE CASE
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int topElement = myStack.top();
    myStack.pop();

    insertAtBottom(myStack, x);

    myStack.push(topElement);
}


void reverse(stack<int> &stack){
    // BASE CASE
    if(stack.empty())
        return;

    int topElement = stack.top();
    stack.pop();

    reverse(stack);

    insertAtBottom(stack, topElement);
}

void reverseStack(stack<int> &stack) {
    reverse(stack);
}