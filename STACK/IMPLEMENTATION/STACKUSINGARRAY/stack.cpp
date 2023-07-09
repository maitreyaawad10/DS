#include <bits/stdc++.h>

using namespace std;

class Stack {
    public:
        int *arr;
        int stackTop;
        int stackSize;

    Stack(int size){
        this -> stackSize = size;
        arr = new int[stackSize];
        stackTop = -1;
    }

    void push(int element){
        if((stackSize - stackTop) > 1){
            stackTop++;
            arr[stackTop] = element;
        }
        else
            cout << "Stack overflow!\n";
    }

    void pop(){
        if(isEmpty())
            cout << "Stack underflow!\n";
        
        else
            stackTop--;
    }

    bool isEmpty(){
        if(stackTop == - 1)
            return true;
        
        return false;
    }

    int topElement(){
        if(stackTop == -1)
            return -1;

        return arr[stackTop];
    }

    void displayStack(){
        int i = 0;

        while(i != stackTop + 1){
            cout << arr[i] << " ";
            i++;
        }

        cout << endl;
    }
};


int main(){
    Stack stack(6);

    stack.push(6);
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);

    stack.displayStack();
    cout << "IS STACK EMPTY? " << stack.isEmpty() << endl;
    cout << "TOP ELEMENT OF STACK IS : " << stack.topElement() << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    // stack.pop();
    // stack.pop();
    // stack.pop();

    stack.displayStack();
    cout << "IS STACK EMPTY? " << stack.isEmpty() << endl;
    cout << "TOP ELEMENT OF STACK IS : " << stack.topElement() << endl;

    return 0;
}