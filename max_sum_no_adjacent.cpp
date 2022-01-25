#include <bits/stdc++.h>
using namespace std;

int algo(vector<int> &vect) {
    int length = vect.size();
    int dp[length];

    dp[0] = vect[0];
    dp[1] = max(dp[0], vect[1]);

    for (int i = 2; i < length; i++) {
        vect[i] = max((vect[i-2] + vect[i]), vect[i-1]);
    }
    return vect[length-1];

}

int main() {
    vector<int> vect{7, 10, 12, 7, 9, 4};
    cout << algo(vect);
    return 0;
}

