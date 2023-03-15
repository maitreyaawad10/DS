#include <bits/stdc++.h> 

using namespace std;

/*
BRUTE FORCE APPROACH, TC : O(M * N)
APPLY LINEAR SEARCH AND SEARCH FOR ELEMENT
*/


// OPTIMAL APPROACH, TC : O(M + N)
bool search(vector<vector<int> > matrix, int m, int n, int x) 
{
    int rows = m;
    int cols = n;
    int i = 0, j = cols - 1, target = x;

    while(i < rows && j >= 0){
        if(matrix[i][j] == target)
            return true;

        if(matrix[i][j] < target)
            i++;
        else if(matrix[i][j] > target)
            j--;
    }

    return false;
}
