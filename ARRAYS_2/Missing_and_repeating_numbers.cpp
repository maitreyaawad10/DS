#include <bits/stdc++.h>

using namespace std;

// BRUTE FORCE APPROACH
// pair<int,int> missingAndRepeating(vector<int> &arr, int n)
// {
// 	// Write your code here
// 	pair<int, int> p;

// 	int a[10001] = {0};

// 	for(int i = 0; i < n; ++i)
// 		a[arr[i]]++;

// 	for(int i = 1; i <= n; ++i){
// 		if(a[i] == 0)
// 			p.first = i;
// 		else if(a[i] > 1)
// 			p.second = i;
// 	}
	
// 	return p;
// }

// OPTIMAL APPROACH, TC : O(N), SC : O(1)
int findDuplicate(vector<int> nums) {
    int ans = -1;

    for(int i = 0; i < nums.size(); ++i){
        int cur = abs(nums[i]);
        if(nums[cur] < 0){
            ans = cur;
            break;
        }
        nums[cur] *= -1;
    }

    return ans;
}

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	pair<int, int> p;

	int repeatingNumber = findDuplicate(arr);
	int ans = 0;

	for (int i = 0; i < arr.size(); ++i) 
		ans = ans ^ arr[i];

	for(int i = 1; i <= n; ++i){
		if(i != repeatingNumber)
			ans = ans ^ i;
	}

	p.first = ans;
	p.second = repeatingNumber;
	
	return p;
}
