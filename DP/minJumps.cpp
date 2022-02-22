#include <bits/stdc++.h>
using namespace std;

int helperFunc(vector<int>& arr, int cur_index, int steps) {
	if (cur_index >=  arr.size()) return steps;
	int num_steps = arr[cur_index];
	int min_steps = INT_MAX;

	for (int i=1; i<=num_steps; ++i) {
		min_steps = min(min_steps, helperFunc(arr, cur_index+i, steps+1));
	}
	return min_steps;
}

int minNumberOfJumps(vector<int> array) {
  return helperFunc(array, 0, 0);
}

/* 
// this one is better
int minNumberOfJumps(vector<int> array) {
  vector<int>dp(array.size());
	dp[0] = 0;
	
	for (int i=1; i<array.size(); ++i) {
		for (int j=0; j<i; ++j) {
			if (array[j]+j >= i) {
				dp[i] = dp[j]+1;
				break;
			}
		}
	}
	return dp.back();
}
*/


int main() {
    vector<int> array{3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3};
    cout << minNumberOfJumps(array);
    return 0;
}