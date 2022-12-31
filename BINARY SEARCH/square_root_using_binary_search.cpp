#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll binarySearch(int x){
    int s = 0, e = x;
    int ans = -1;

    while(s <= e){
        ll m = s + ((e - s) / 2);

        if(m * m == x)
            return m;
        
        if(m * m < x){
            ans = m;
            s = m + 1;
        }
        
        else
            e = m - 1;
    }

    return ans;
}

int mySqrt(int x) {
    return binarySearch(x);
}

double morePrecision(int n, int precision, int tempSol){
    double factor = 1, ans = tempSol;

    for(int i = 0; i < precision; ++i){
        factor /= 10;

        for(double j = ans; j * j <= n; j += factor){
            ans = j;
        }
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    int tempSol = mySqrt(n);

    cout << morePrecision(n, 3, tempSol) << endl;

    return 0;
}