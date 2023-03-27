#include <bits/stdc++.h> 

using namespace std;

// BRUTE FORCE APPROACH, TC : O(N! * N + (N! * LOG(N!)))
// ALL PERMUTATIONS OF STRING
void findPermutations(string &s, vector<string> &ans, int index){
    if(index >= s.length()){
        ans.push_back(s);
        return;
    }

    for(int i = index; i < s.size(); ++i){
        swap(s[i], s[index]);
        findPermutations(s, ans, index + 1);
        swap(s[i], s[index]);
    }
}

string getPermutation(int n, int k) {
    string s = "";
    for(int i = 1; i <= n; ++i){
        char x = i + '0';
        s.push_back(x);
    }

    vector<string> ans;
    findPermutations(s, ans, 0);
    sort(ans.begin(), ans.end());

    return ans[k - 1];
}


// OPTIMAL APPROACH
