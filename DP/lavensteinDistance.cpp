#include <bits/stdc++.h>
using namespace std;
 
int minm(int a, int b, int c) {
	return min(a, min(b, c));
}

int levenshteinDistance(string str1, string str2) {
	int l1 = str1.length(), l2 = str2.length();
    int dp[l1+1][l2+1];
	
	for (int i=0; i<=l1; ++i)
		dp[i][0] = i;
	for (int i=0; i<=l2; ++i)
		dp[0][i] = i;
	
	for (int i=1; i<=l1; ++i) {
		for (int j=1; j<=l2; ++j) {
			if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else {
				dp[i][j] = 1+minm(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]);
			}
		}
	}

	return dp[l1][l2];
}

int main() {
    cout << levenshteinDistance("1234", "abcd");
    return 0;
}