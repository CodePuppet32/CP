#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> arr) {
    for (int i: arr) {
          cout << i << " ";
    }
    cout << endl;
}
 
bool canBePut(vector<int> a, vector<int> b) {
	return (a[0] > b[0] && a[1] > b[1] && a[2] > b[2]);
}

int diskStacking(vector<vector<int>> disks) {
  vector<int> dp(disks.size());
	dp[0] = disks[0][2];
	
	// I can either put it above previous
	// I can start new stack if curr disk height is greater than prev stack
	// I can skip this disk
	int maxm = dp[0];
    int maxi = 0;

	for (int i=1; i<disks.size(); ++i) {
		dp[i] = disks[i][2];
		for (int j=0; j<i; ++j) {
            if (canBePut(disks[i], disks[j])) {
                dp[i] = max(dp[i], disks[i][2]+dp[j]);
            }
            if (dp[i] > maxm) {
                maxm = dp[i];
                maxi = i;
            }
        }
	}
    vector<vector<int>> res;
    int cur_max = disks[maxi][2];

    for (int j=0; j<maxi; ++j) {
        if (canBePut(disks[maxi], disks[j])) {
            if (cur_max < cur_max+dp[j]) {
                cur_max = cur_max+dp[j];
                res.push_back(disks[j]);
            }
        }
    }

    return res;
}

int main() {
    vector<vector<int>> disks{  {2, 1, 2},
                                {3, 2, 3},
                                {2, 2, 8},
                                {4, 3, 4},
                                {1, 3, 1},
                                {4, 4, 5} };
    
    cout << diskStacking(disks);
    return 0;
}