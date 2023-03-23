#include <bits/stdc++.h> 

using namespace std;

void solve(string str, vector<string>& ans, int index, string s){
	if(index >= str.length()){
		if(s.length() > 0)
			ans.push_back(s);
		return;
	}
	
	// excluding the current character
	solve(str, ans, index + 1, s);

	// including the current character
	char x = str[index];
	s.push_back(x);
	solve(str, ans, index + 1, s);
}

vector<string> subsequences(string str){
	
	// Write your code here
	int index = 0;
	vector<string> ans;
	string s = "";
	solve(str, ans, index, s);

	return ans;
}