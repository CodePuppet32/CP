#include <bits/stdc++.h>
using namespace std;


void algo(string s, int start, int end) {
    if (start == end) {
        cout << s << endl;
        return;
    }
    
    algo(s, start+1, end);
    for (int i = start+1; i < end; i++) {
        swap(s[start], s[i]);
        algo(s, start+1, end);
        swap(s[start], s[i]);
    }
}

int main() {
    algo("ABC", 0, 3);
    return 0;
}

