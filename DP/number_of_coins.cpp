#include <bits/stdc++.h>
using namespace std;

int algo(vector<int> &vect, int change) {
    int dp[change+1];
    fill(dp, dp+change+1, 0);
    dp[0] = 1;

    // run a loop for every coin that we have
    for (int i = 0; i < vect.size(); i++) {
        // check if we can use the coin to add up to change
        for(int j = 1; j < change+1; j++) {
            if (j >= vect[i]) {
                dp[j] += (dp[j-vect[i]]);
            }
        }
    }

    return dp[change];
}

int main() {
    vector<int> vect{1, 5, 10, 25};
    cout << algo(vect, 10);
    return 0;
}

