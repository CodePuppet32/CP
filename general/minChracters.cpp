#include <bits/stdc++.h>
using namespace std;

vector<char> min_words(vector<string>& words) {
    unordered_map<char, int> map;
    for (auto character: words[0]) {
        map[character] += 1;
    }
    vector<char> res;
    if (words.size() == 0)
        return res;
    
    for (int i=1; i<words.size(); ++i) {
        unordered_map<char, int> temp_map;
        for (auto character: words[i]) {
            if (temp_map[character])
                temp_map[character] += 1;
            else
                temp_map[character] = 1;

            if (map[character]) {
                map[character] = max(map[character], temp_map[character]);
            } else {
                map[character] = 1;
            }
        }
    }

    for (auto character: map) {
        while (character.second--)
            res.push_back(character.first);
    }
    return res;
}

int main() {
    vector<string> words{"this", "that", "did", "deed", "them!", "@"};
    vector<char> res = min_words(words);
    for (auto character: res) {
        cout << character << " ";
    }
    return 0;
}