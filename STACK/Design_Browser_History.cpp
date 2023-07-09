#include <bits/stdc++.h>

using namespace std;

class BrowserHistory {
    stack<string> first, second;

public:
    BrowserHistory(string homepage) {
        first.push(homepage);
    }
    
    void visit(string url) {
        if(!second.empty()){
            while(!second.empty()) {   
                second.pop();
            }
        }

        first.push(url);
    }
    
    string back(int steps) {
        int firstSize = first.size();

        for(int i = 0; i < min(firstSize, steps); ++i){
            string firstTop = first.top();
            first.pop();
            second.push(firstTop);
        }

        if(first.empty()){
            first.push(second.top());
            second.pop();
        }
        
        return first.top();
    }
    
    string forward(int steps) {
        int secondSize = second.size();

        for(int i = 0; i < min(secondSize, steps); ++i){
            string secondTop = second.top();
            second.pop();
            first.push(secondTop);
        }

        return first.top();
    }
};
