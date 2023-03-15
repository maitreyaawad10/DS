#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    int minValue = INT_MAX, profit = 0;

    for(auto value : prices){
        minValue = min(minValue, value);
        profit = max(profit, value - minValue);
    }
    
    return profit;
}

int main(){


    return 0;
}