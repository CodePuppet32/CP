#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int len;
        cin >> len;
        int count_d = 0, count_a = 0;
        for (int i = 0; i < len; i++) {
            int winner;
            cin >> winner;
            if (winner == 'D' )
                ++count_d;
            else
                ++count_a;
        }
        if (count_d > count_a) {
            cout << "Danish";
        } else {
            cout << "Aditya";
        }
    }
    
    return 0;
}