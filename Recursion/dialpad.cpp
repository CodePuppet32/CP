#include <bits/stdc++.h>
using namespace std;

vector<string> dialpad{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void helpFunc(string &soFar, int dialed) {
    // base case
    if(dialed == 0) {
        cout << soFar << endl;
        return;
    }

    int cur_num = dialed%10;

    for (int i=0; i < dialpad[cur_num].length(); i++) {
        soFar.push_back(dialpad[cur_num][i]);
        helpFunc(soFar, dialed/10);
        soFar.pop_back();
    }
    
}

int algo(int dialed) {
    string soFar = "";
    string str_dialed = to_string(dialed);
    reverse(str_dialed.begin(), str_dialed.end());
    dialed = stoi(str_dialed);
    helpFunc(soFar, dialed);
}

int main() {
    int dialed = 47724;
    algo(dialed);
    return 0;
}

