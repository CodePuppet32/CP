#include <bits/stdc++.h>
using namespace std;

int knapsackProblem(vector<vector<int>> items, int capacity) {
    int dp[items.size()+1][capacity+1];
	for (int i=0; i<=items.size(); ++i) {
		for (int j=0; j<=capacity; ++j) {
			dp[i][j] = 0;
		}
	}

	for (int i=1; i<=items.size(); ++i) {
        for (int j=1; j<=capacity; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j >= items[i-1][1]) {
                dp[i][j] = max(items[i-1][0] + dp[i-1][j-items[i-1][1]], dp[i-1][j]);
            }
        }
    }

	return dp[items.size()][capacity];
}

int main() {
    vector<vector<int>> items{{1, 2}, {4, 4}, {5, 6}, {6, 7}};
    cout << knapsackProblem(items, 10);
    return 0;
}

