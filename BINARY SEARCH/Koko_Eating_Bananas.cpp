#include <bits/stdc++.h>

using namespace std;

bool isPossibleToEat(vector<int>& piles, int h, int k){
    int currentHour = 0;
    
    for(int i = 0; i < piles.size(); ++i){
        if(piles[i] <= k)
            currentHour += 1;

        else {
            int x = piles[i];
            if((x % k) != 0)
                currentHour += ((x / k) + 1);
            else
                currentHour += (x / k);
        }

        if(currentHour > h)
            return false;
    }

    return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int s = 0, e = 1e9, ans = -1;

    if(piles.size() == 1 && h > piles[0])
        return 1;

    while(s <= e){
        int k = s + (e - s) / 2;

        if(k == 0)
            return ans;

        if(isPossibleToEat(piles, h, k)){
            ans = k;
            e = k - 1;
        }

        else
            s = k + 1;
    }

    return ans;
}

int main(){


    return 0;
}