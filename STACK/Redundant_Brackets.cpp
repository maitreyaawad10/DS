#include <bits/stdc++.h> 

using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for(int i = 0; i < s.length(); ++i){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);

        else if(ch == ')') {
            bool operatorPresent = false;

            while(st.top() != '('){
                char top = st.top();
                st.pop();

                if(top == '+' || top == '-' || top == '*' || top == '/')
                    operatorPresent = true;
            }

            st.pop();

            if(operatorPresent == false)
                return true;
        }
    }

    return false;
}