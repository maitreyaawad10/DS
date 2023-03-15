#include <bits/stdc++.h>

using namespace std;

void printPascal(int n) 
{
    vector<vector<long long int>> pascal;
          
    for(long long int i = 0; i < n; ++i){

        vector<long long int> row;
        row.push_back(1);
        
        for(long long int j = 1; j < i; ++j)
            row.push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
        
        if(i != 0)
            row.push_back(1);

        pascal.push_back(row);
    }

    for(long long int i = 0; i < n; ++i){
        for(long long int j = 0; j < i + 1; ++j)
            cout << pascal[i][j] << " ";

        cout << endl;
    }
    cout << endl;
    
    cout << pascal[n - 1][2] << endl;
}

int main(){
    long long int n = 5;

    printPascal(n);

    return 0;
}