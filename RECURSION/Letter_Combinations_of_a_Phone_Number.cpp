#include <bits/stdc++.h> 

using namespace std;

void findCombinations(string digits, vector<string> &ans, string mapping[], string output, int index){
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }

    int currentDigit = digits[index] - '0';
    string value = mapping[currentDigit];

    for(int i = 0; i < value.length(); ++i){
        output.push_back(value[i]);
        findCombinations(digits, ans, mapping, output, index + 1);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string output = "";

    if(digits.length() == 0)
        return ans;

    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int index = 0;
    findCombinations(digits, ans, mapping, output, index);

    return ans;
}