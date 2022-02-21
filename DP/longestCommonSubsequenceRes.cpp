#include <bits/stdc++.h>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
	int l1=str1.length()+1, l2=str2.length()+1;
	vector<vector<vector<char>>>res(l1, vector<vector<char>>(l2));

	for (int i=1; i<l1; ++i) {
		for (int j=1; j<l2; ++j) {
			if (str1[i-1] == str2[j-1]) {
				res[i][j] = res[i-1][j-1];
				res[i][j].push_back(str1[i-1]);
			} else {
				if (res[i-1][j].size() > res[i][j-1].size()) {
					res[i][j] = res[i-1][j];
				} else {
					res[i][j] = res[i][j-1];
				}
			}
		}
	}
	return res[l1-1][l2-1];
}

int main() {
    vector<char> res;
    res = longestCommonSubsequence("ZXVVYZW", "XKYKZPW");
    for (auto i: res)
        cout << i << ", ";
    return 0;
}