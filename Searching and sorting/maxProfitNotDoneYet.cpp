#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> arr) {
    for (int i: arr) {
          cout << i << " ";
    }
    cout << endl;
}
 
int maxProfit(vector<vector<int>> table, int length, int index, int res, vector<int>& dp) {
    if (length == 0) return 0;
    if (length < 0 || index == table.size()) return 0;

    return 0;
}

int main() {
    vector<vector<int>> table{{1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
    int length = 20;
    vector<vector<int>> dp(length+1, vector<int>(length+1, 0));
    cout << dp.size() << " " << dp[0].size();
    //cout << maxProfit(table, length, 0, 0, dp);
    return 0;
}