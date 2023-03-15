#include <bits/stdc++.h> 

using namespace std;

// BRUTE FORCE, TC : O(N)
// USE NORMAL FOR LOOP TO FIND X ^ N

// X^N = ?
// OPTIMAL APPROACH, TC : O(LOG(N))
double myPow(double x, int n) {
    double ans = 1.0;
    long long nn = n;

    if(nn < 0)
        nn *= -1;

    while(nn){
        if(nn % 2 == 0){
            x *= x;
            nn /= 2;
        }
        else {
            ans = ans * x;
            nn -= 1;
        }
    }

    if(n < 0)
        ans = double(1.0) / double(ans);
    
    return ans;
}