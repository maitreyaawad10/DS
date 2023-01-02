#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool isWoodSufficient(vector<ll> &trees, ll n, ll m, ll mid){
    ll wood = 0;

    for(ll i = 0; i < n; ++i){
        if(trees[i] >= mid)
            wood += (trees[i] - mid);    
    }

    return (wood >= m);
}

ll binarySearch(vector<ll> &trees, ll n, ll m){
    ll s = 0, e = 1e9;
    ll ans = -1;

    while(s <= e){
        ll mid = s + ((e - s) / 2);

        if(isWoodSufficient(trees, n, m, mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }

    return ans;
}

void solve(){
    ll n, m;
    cin >> n >> m;

    vector<ll> trees;

    for(ll i = 0; i < n; ++i){
        int x;
        cin >> x;
        trees.push_back(x);
    }    

    cout << binarySearch(trees, n, m) << endl;
}

int main(){
    solve();

    return 0;
}