#include <bits/stdc++.h>

using namespace std;

double eps = 1e-6;	

double multiply(double mid, int n){
	double ans = 1;
	for(int i = 0; i < n; ++i){
		ans *= mid;
	}

	return ans;
}


// Time Complexity ==>> N * (log(X * (10^d)))	// for nth root of x
int main(){
	double x;
	int n;
	cin >> x >> n;

	double low = 1, high = x, mid;

	while(high - low > eps){
		mid = (low + high) / 2;

		if(multiply(mid, n) < x){
			low = mid;
		}

		else{
			high = mid;
		}
	}

	cout << setprecision(7) << low << "\n" << high << endl;

	return 0;
}
