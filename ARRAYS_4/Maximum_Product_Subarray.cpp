#include <bits/stdc++.h>

using namespace std;

// OPTIMAL APPROACH, TC : O(N), SC : O(1)
int subarrayWithMaxProduct(vector<int> &arr){
	int pf = 1, sf = 1;
	int maxProduct = INT_MIN;
	int n = arr.size();

	for(int i = 0; i < n; ++i){
		if(pf == 0)	pf = 1;
		if(sf == 0) sf = 1;

		pf = pf * arr[i];
		sf = sf * arr[n - i - 1];

		maxProduct = max(maxProduct, max(pf, sf));
	}

	return maxProduct;
}
