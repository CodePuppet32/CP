#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string a, string b) {
    int l1 = a.length(), l2 = b.length();
    int dp[l1+1][l2+1];
    for (int i=0; i<=l1; ++i) {
        fill(dp[i], dp[i]+l2+1, 0);
    }
    
    for (int i=1; i<=l1; ++i) {
        for (int j=1; j<=l2; ++j) {
            if (a[i-1]==b[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[l1][l2];
}
 
int main() {
    string s1 = "branch", s2 = "workattech";
    cout << longestCommonSubsequence(s1, s2) << endl;   
    return 0;
}