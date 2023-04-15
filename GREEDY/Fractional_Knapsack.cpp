#include <bits/stdc++.h> 

using namespace std;

bool sortbysecdesc(const pair<double,double> &a, const pair<double,double> &b){
    double r1 = (double)a.second / (double)a.first;
    double r2 = (double)b.second / (double)b.first;
    
    return (r1 > r2);
}

double maximumValue(vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), sortbysecdesc);
    
    double profit = 0.0;
    
    for(int i = 0; i < n; ++i){
        if(items[i].first <= w){
            profit += items[i].second;
            w -= items[i].first;
        }

        else{
            double remProfit = ((double)w / (double)items[i].first) * (double)items[i].second;
            profit += remProfit;
            break;
        }
    }

    return profit;
}