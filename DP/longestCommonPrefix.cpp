#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> arr) {
    for (int i: arr) {
          cout << i << " ";
    }
    cout << endl;
}
 
string longestCommonPrefix(vector<string>& strs) {
    string lcp = "";
    int cur_index=0;
    
    while (1) {
        if (cur_index >= strs[0].length())
            return lcp;
        for (int i=1; i<strs.size(); ++i) {
            if (cur_index >= strs[i].length())
                return lcp;
            else if(strs[i][cur_index] != strs[i-1][cur_index])
                return lcp;
        }
        lcp.push_back(strs[0][cur_index]);
        ++cur_index;
    }
}

int main() {
    vector<string> strs{"flower", "flirt", "flying"};
    cout << longestCommonPrefix(strs);
    return 0;
}