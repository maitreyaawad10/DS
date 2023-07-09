#include <bits/stdc++.h>

using namespace std;

#define ll long long

int firstCircularTour(vector<int> &petrol, vector<int> &distance, int N)
{
    ll deficit = 0;
    ll balance = 0;
    int start = 0;

    for (ll i = 0; i < N; ++i)
    {
        balance += petrol[i] - distance[i];

        if (balance < 0)
        {
            deficit += balance;
            balance = 0;
            start = i + 1;
        }
    }

    if ((balance + deficit) < 0)
        return -1;
    else
        return start;
}
