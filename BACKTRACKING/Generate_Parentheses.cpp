void parenthesis(int n, vector<string>& ans, string& s, int open, int close) {
	if(open == close && open == n){
	    ans.push_back(s);
	    return;
	}

	if(open < n){
	    s.push_back('(');
	    parenthesis(n, ans, s, open + 1, close);
	    s.pop_back();
	}

	if(close < open){
	    s.push_back(')');
	    parenthesis(n, ans, s, open, close + 1);
	    s.pop_back();
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> ans;
	string s;
	int open = 0, close = 0;

	parenthesis(n, ans, s, open, close);

	return ans;
}
