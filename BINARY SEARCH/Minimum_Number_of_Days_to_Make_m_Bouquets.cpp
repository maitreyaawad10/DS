#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int>& bloomDay, int m, int k, int minTime){
    int flowerCount = 0, bouquetCount = 0;

    for(int i = 0; i < bloomDay.size(); ++i){
        if(bloomDay[i] <= minTime){
            flowerCount++;

            if(flowerCount == k){
                bouquetCount++;
                
                if(bouquetCount == m)
                    return true;
                
                flowerCount = 0;
            }
        }

        else
            flowerCount = 0;
    }

    return false;
}

int minDays(vector<int>& bloomDay, long long m, long long k) {
    int s = 0, e = 1e9, ans = -1;

    if(m * k > bloomDay.size()) 
        return ans;

    while(s <= e){
        int minTime = s + (e - s) / 2;

        if(isPossible(bloomDay, m, k, minTime)){
            ans = minTime;
            e = minTime - 1;
        }

        else
            s = minTime + 1;
    }

    return ans;
}

int main(){


    return 0;
}