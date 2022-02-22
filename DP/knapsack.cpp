#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getSequence(vector<vector<int>>& items, vector<vector<int>>& dp, int maxCapacity) {
    vector<int>bag;

    int row=items.size();
    int col=dp[0].size()-1;

    while (row >= 1) {
        if (dp[row][col] != dp[row-1][col]) {
            col -= items[row-1][1];
            bag.push_back(row-1);
        }
        --row;
    }
    reverse(bag.begin(), bag.end());
    return {
        {maxCapacity},
        {bag}
    };
}

vector<vector<int>> knapsack(vector<vector<int>>& items, int capacity) { 
    vector<vector<int>> dp{items.size()+1, vector<int>(capacity+1, 0)};

	for (int i=1; i<=items.size(); ++i) {
			for (int j=1; j<=capacity; ++j) {
					if(j >= items[i-1][1]) {
							dp[i][j] = max(dp[i-1][j], items[i-1][0] + dp[i-1][j-items[i-1][1]]);
					} else {
							dp[i][j] = dp[i-1][j];
					}
			}
	}
	return getSequence(items, dp, dp[items.size()][capacity]);
}

int main() {
    // 0 - value 1 - weight
    vector<vector<int>> items{{10, 2}, {4, 3}, {5, 6}, {6, 7}};
    vector<vector<int>> res = knapsack(items, 10);

    for (auto row: res) {
        for (auto col: row) {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}