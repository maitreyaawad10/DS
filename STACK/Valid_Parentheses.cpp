#include <bits/stdc++.h> 

using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;

    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        
        else if(!st.empty()){
            if (((s[i] == ')') && (st.top() != '(')) || ((s[i] == '}') && (st.top() != '{')) || ((s[i] == ']') && (st.top() != '[')))
                return false;
            
            else
                st.pop();
        }

        else
            return false;
    }

    if(!st.empty())
        return false;

    return true;
}