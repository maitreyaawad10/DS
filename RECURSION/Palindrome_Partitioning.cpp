#include <bits/stdc++.h> 

using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--])
            return false;
    }

    return true;
}

void findPartitions(string s, vector<vector<string>> &ans, vector<string> &path, int index){
    if(index == s.size()){
        ans.push_back(path);
        return;
    }

    for(int i = index; i < s.size(); ++i){
        if(isPalindrome(s, index, i)){
            path.push_back(s.substr(index, i - index + 1));
            findPartitions(s, ans, path, i + 1);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    int index = 0;

    findPartitions(s, ans, path, index);

    return ans;
}