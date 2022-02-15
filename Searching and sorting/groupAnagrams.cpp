#include <bits/stdc++.h>
using namespace std;

bool are_anagrams(string s1, string s2) {
	if (s1.length() != s2.length()) return false;
	int arr[26];
	fill(arr, arr+26, 0);
	
	for (int i=0; i<s1.length(); ++i) {
		++arr[s1[i]-'a'];
		--arr[s2[i]-'a'];
	}
	for (int i=0; i<26; ++i) {
		if (arr[i]) 
			return false;
	}
	return true;
}

vector<vector<string>> groupAnagrams(vector<string> words) {
  vector<vector<string>> res;
	bool hasAdded[words.size()];
	fill(hasAdded, hasAdded+words.size(), false);
	
	for (int i=0; i<words.size(); ++i) {
		if (hasAdded[i] == false) {
			hasAdded[i] = true;
			vector<string> temp;
			temp.push_back(words[i]);
			for (int j=i+1; j<words.size(); ++j) {
				if (hasAdded[j] == false) {
					if (are_anagrams(words[i], words[j])) {
						temp.push_back(words[j]);
						hasAdded[j] = true;
					}
				}
			}
			res.push_back(temp);
		}
	}
	
	return res;
}

int main() {
    vector<string> words {"yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp"};
    vector<vector<string>> res = groupAnagrams(words);
    for (int i=0; i<res.size(); ++i) {
        for (int j=0; j<res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}