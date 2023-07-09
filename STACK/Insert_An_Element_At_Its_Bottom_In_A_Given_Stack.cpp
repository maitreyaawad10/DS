#include <bits/stdc++.h> 

using namespace std;

void solve(stack<int>& myStack, int x){
    // BASE CASE
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int topElement = myStack.top();
    myStack.pop();

    solve(myStack, x);

    myStack.push(topElement);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);

    return myStack;
}
