#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>& a, int n)
{   
    for(int i = 1; i < n; ++i){
        bool swapped = false;
        for(int j = 0; j < n - i; ++j){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}

int main(){
    

    return 0;
}