#include <bits/stdc++.h>
using namespace std;

int firstNonRepeatingCharacter(string string) {
  vector<int> map(26, -1);
	for (int i=0; i<string.size(); ++i) {
		if (map[string[i]-'a'] == -1)
			map[string[i]-'a'] = i;
		else
			map[string[i]-'a'] = -2;	
	}
	int res = INT_MAX;
	for (int i=0; i<26; ++i) {
		if (map[i] >= 0) 
			res = min(res, map[i]);
	}
	return res==INT_MAX? -1: res;
}

int main() {
    cout << firstNonRepeatingCharacter("aabbccddee");
    return 0; //return
}