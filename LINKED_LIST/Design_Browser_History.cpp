#include <bits/stdc++.h>

using namespace std;

class BrowserHistory {
public:
    struct Node {
        string page;
        Node* prev;
        Node* next;

        Node(string homepage){
            page = homepage;
            prev = NULL;
            next = NULL;
        }
    };

    Node* curr;

    BrowserHistory(string homepage) {
        Node* newNode = new Node(homepage);
        curr = newNode;
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        curr -> next = newNode;
        newNode -> prev = curr;
        curr = newNode;
    }
    
    string back(int steps) {
        while(curr -> prev != NULL && steps){
            curr = curr -> prev;
            steps--;
        }

        return curr -> page;
    }
    
    string forward(int steps) {
        while(curr -> next != NULL && steps) {
            curr = curr -> next;
            steps--;
        }

        return curr -> page;
    }
};

