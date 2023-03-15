#include <bits/stdc++.h> 

using namespace std;

// BRUTE FORCE APPROACH, TC : 2^N, SC : 2^N
// APPROACH : TRY OUT ALL POSSIBLE PATHS USING RECURSION
int countPaths(int i, int j, int m, int n){
    if(i == m - 1 && j == n - 1)    return 1;
    if(i >= m || j >= n)    return 0;
    return countPaths(i + 1, j, m, n) + countPaths(i, j + 1, m, n);
}
int uniquePaths(int m, int n) {
    return countPaths(0, 0, m, n);
}

// OPTIMAL APPPROACH, TC : O(M - 1) OR O(N - 1), SC : O(1) 
// APPROACH : COMBINATORICS
int uniquePaths(int m, int n) {
    int N = m + n - 2;
    int r = m - 1;
    double res = 1;

    for(int i = 1; i <= r; ++i){
        res = res * (N - r + i) / i;
    }

    return (int)res;
}