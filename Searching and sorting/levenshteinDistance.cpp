#include <bits/stdc++.h>
using namespace std;

int levenshteinDistance(string str1, string str2, int i=0, int j=0) {
	int l1 = str1.length(), l2 = str2.length();
    if (i == l1 || j == l2) {
        if (l1 == i)
            return l2-j;
        else
            return l1-i;
    }
    if (str1[i] == str2[j]) {
        return levenshteinDistance(str1, str2, i+1, j+1);
    } 
    if (l1 > l2) {
        return 1+min(min(levenshteinDistance(str1, str2, i+1, j), levenshteinDistance(str1, str2, i+1, j+1)), levenshteinDistance(str1, str2, i, j+1));
    } else {
        return 1+min(min(levenshteinDistance(str1, str2, i, j+1), levenshteinDistance(str1, str2, i+1, j+1)), levenshteinDistance(str1, str2, i+1, j));
    }
}


int main() {
    cout << levenshteinDistance("abcd", "cabd");
    return 0;
}