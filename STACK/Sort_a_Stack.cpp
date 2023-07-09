#include <bits/stdc++.h> 

using namespace std;

void insertAtSortedPosition(stack<int> &stack, int element){
	if(stack.empty() || stack.top() <= element){
		stack.push(element);
		return;
	}

	int x = stack.top();
	stack.pop();

	insertAtSortedPosition(stack, element);
	
	stack.push(x);
}


void sortStack(stack<int> &stack)
{
	if(stack.empty())
		return;

	int topElement = stack.top();
	stack.pop();

	sortStack(stack);

	insertAtSortedPosition(stack, topElement);
}