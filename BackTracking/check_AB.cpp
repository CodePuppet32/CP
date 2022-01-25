#include <bits/stdc++.h>
using namespace std;

bool algo(string s, int cur_index, bool is_b) {
    // base case -> first element 'a'
    if (cur_index == 0) 
        return s[0] == 'a';

    // if we have already encountered 'b'
    if (is_b) {
        // if 'b' is not followed by 'b' or 2 'b's are followed by another 'b'
        if (s[cur_index] != 'b' || s[cur_index-1] == 'b')
            return false;
    } 
    // if we are encountering first 'b'
    else if (s[cur_index] == 'b') {
        return algo(s, cur_index - 1, true);
    }
    return algo(s, cur_index-1, false);
}

int main() {
    string s = "abbaaaaabba";
    cout << algo(s, s.length()-1, false);
    return 0;
}

