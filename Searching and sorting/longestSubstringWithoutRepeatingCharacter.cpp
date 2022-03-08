#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> arr) {
    for (int i: arr) {
          cout << i << " ";
    }
    cout << endl;
}
 
int longestSubstringWithoutRepeat(string s) {
    int res = 1;

	vector<int> map(26, -1);
	int substr_beg = 0;
	int i = 0;
	
	for (i; i<s.length(); ++i) {
		// if this character is not already present or it is present but not in out window
		if (map[s[i]-'a'] == -1 || map[s[i]-'a'] < substr_beg) {
			map[s[i]-'a'] = i;
		} else {
			// this character is already present -> update the res and substr_beg
			res = max(res, (i-substr_beg));
			substr_beg = map[s[i]-'a']+1;
			map[s[i]-'a'] = i;
		}
	}
	res = max(res, (i-substr_beg));
	return res;
}

int main() {
    cout << longestSubstringWithoutRepeat("mississippi");
    return 0;
}