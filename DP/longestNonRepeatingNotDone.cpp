#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> arr) {
    for (int i: arr) {
          cout << i << " ";
    }
    cout << endl;
}
 

int lengthOfLongestSubstring(string s) {
    int res=0, begin=0;
    int hasVisited[256];
    fill(hasVisited, hasVisited+256, -1);

    for (int i=0; i<s.length(); ++i) {
        if (hasVisited[s[i]] != -1) {
            begin = hasVisited[s[i]]+1;
        } else {
            hasVisited[s[i]] = i;
            res = max(res, (i-begin+1));
        }
    }

    return res;
}

int main() {
    string s = "tmmzuxt";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}

