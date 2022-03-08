#include <bits/stdc++.h>
using namespace std;

bool areAnagrams(string A, string B) {
    if (A.length() != B.length())
		return false;
	vector<int>mapm(26, 0);
	cout << A.length();
    int i = 0;
	for (i = 0; i<A.length(); ++i) {
        
		++mapm[A[i]-'a'];
		--mapm[B[i]-'a'];
	}
	for (int i=0; i<26; +i) {
		if (mapm[i])
			return false;
	}
	return true;
}

int main() {
    cout << areAnagrams("apple", "pplae");
    return 0;
}