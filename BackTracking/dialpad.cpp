#include <bits/stdc++.h>
using namespace std;

vector<string> phone_map {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void helperFunc(vector<string>& res, string& phoneNumber, string& cur_str, int cur_index) {
	// base case when we have processed all of our phoneNumber string;
	if (cur_index == phoneNumber.length()) {
		res.push_back(cur_str);
		return;
	}
	// Now for every digit in phone number we can either use a character or skip it
    
	for (int i=0; i<phone_map[int(phoneNumber[cur_index]-'0')].length(); ++i) {
		cur_str.push_back(phone_map[int(phoneNumber[cur_index]-'0')][i]);
		helperFunc(res, phoneNumber, cur_str, cur_index+1);
		cur_str.pop_back();
	}
}


vector<string> phoneNumberMnemonics(string phoneNumber) {
	vector<string> res;
    string cur_str = "";
	helperFunc(res, phoneNumber, cur_str, 0);
	return res;
}

int main() {
    string phoneNumber = "1905";
    vector<string> res;
    res = phoneNumberMnemonics(phoneNumber);
    for (int i=0; i<res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;
}