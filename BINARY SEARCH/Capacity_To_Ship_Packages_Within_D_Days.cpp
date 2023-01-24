#include <bits/stdc++.h>

using namespace std;

bool canShipWithinDays(vector<int>& weights, int days, int leastWeight){
    int lastDay = 1, currentWeight = 0;

    for(int i = 0; i < weights.size(); ++i){
        if((weights[i] + currentWeight) <= leastWeight)
            currentWeight += weights[i];

        else{
            lastDay++;

            if(lastDay > days || weights[i] > leastWeight)
                return false;

            currentWeight = weights[i];
        }
    }

    return true;
}

int shipWithinDays(vector<int>& weights, int days) {
    int s = 0, e = 1e9, ans = -1;

    if(weights.size() == days) {
        ans = *max_element(weights.begin(), weights.end());
        return ans;
    }

    while(s <= e){
        int leastWeight = s + (e - s) / 2;

        if(canShipWithinDays(weights, days, leastWeight)){
            ans = leastWeight;
            e = leastWeight - 1;
        }

        else
            s = leastWeight + 1;
    }

    return ans;
}

int main(){
    vector<int> weights = {93, 41, 3, 14, 21, 51, 57, 79, 4, 23, 25};
    int days = 10;

    cout << shipWithinDays(weights, days) << endl; 

    return 0;
}