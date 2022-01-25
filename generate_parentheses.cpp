#include <bits/stdc++.h>
using namespace std;

void helpFunc(string &soFar, int open, int close) {
    // base case
    if(open < 0 || close < 0) return;

    // answer case
    if(open == 0 && close == 0) {
        cout << soFar << endl;
    }

    if(open <= close) {
        // recursive case
        soFar.push_back('(');
        helpFunc(soFar, open-1, close);
        soFar.pop_back();
        soFar.push_back(')');
        helpFunc(soFar, open, close-1);
        soFar.pop_back();
    }
    
}

int algo(int open, int close) {
    string soFar = "";
    helpFunc(soFar, open, close);
}

int main() {
    int open = 100;
    int close = 100;
    algo(open, close);
    return 0;
}

