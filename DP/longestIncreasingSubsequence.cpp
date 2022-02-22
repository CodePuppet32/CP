#include <bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(vector<int> arr) {
	vector<int> dp(arr.size(), 1);
	vector<int> indices(arr.size(), -1);
	int maxi=0, res=0;

	for (int i=1; i<arr.size(); ++i)
		for (int j=0; j<i; ++j) {
			// if the scanned element is smaller
			if (arr[j] < arr[i]) {
				// also the smaller element i
				if (dp[j]+1 > dp[i]) {
					// update the ith col
					dp[i] = dp[j]+1;
					// also update the index
					indices[i] = j;
					// if we have new maxima update it
					if (dp[i] > res){
						res = dp[i];
						maxi = i;
					}
				}
			}
		}
	vector<int> ar;
	while (maxi != -1){
		ar.push_back(arr[maxi]);
		maxi = indices[maxi];
	}
	
	reverse(ar.begin(), ar.end());
	
	
	return ar;
}

int main() {
    vector<int> arr{5, 7, -24, 12, 10, 2, 3, 12, 5, 6, 35};
    vector<int> res = longestIncreasingSubsequence(arr);
    for (auto i: res) {
        cout << i << " ";
    }
    return 0;
}