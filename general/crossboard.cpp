#include <bits/stdc++.h>
using namespace std;

void resetVertical(char crossboard[10][10], int x, int y, int length, int skip_index=-1) {
    for (int i = x; i < length+x; i++) {
        if (i != skip_index) {
            crossboard[i][y] = '-';
        }
    }
}
void resetHorizontal(char crossboard[10][10], int x, int y, int length, int skip_index=-1) {
    for (int i = y; i < length+y; i++) {
        if (i != skip_index) {
            crossboard[x][i] = '-';
        }
    }
}
bool isValidVertical(char crossboard[10][10], string word, int row, int column) {
    int len = 1;
    int str_len = word.length();

    // count the number of valid spaces
    for (int i = row+1; i < 10; i++) {
        if (crossboard[i][column] != '+')
            ++len;
    }
    // if the number of valid spaces are equal to the lenght of the word return the len otherwise 0
    return len == str_len;
}
bool isValidHorizontal(char crossboard[10][10], string word, int row, int column) {
    int len = 1;
    int str_len = word.length();
    int word_index = 0;

    // count the number of valid spaces
    for (int i = column+1; i < 10; i++) {
        if (crossboard[i][row] != '+')
            break;
        if (crossboard[i][row] != '-')
            len++;
        else if(word[word_index] != crossboard[i][column])
        
        
    }
    // if the number of valid spaces are equal to the lenght of the word return the len otherwise 0
    return len == str_len;
}
// we know for sure that current word will fit in this configuration
// we only need to check for conflicting words
bool setHorizontal(char crossboard[10][10], string word, int row, int column) {
    int word_index = 0;
    int word_length = word.length();

    for (int i=column; i<column+word_length; i++) {
        // if the crossboard has a words we need to check whether it matches with the word
        if (crossboard[row][i] != '-' && crossboard[row][i] != word[word_index]) {
            resetHorizontal(crossboard, row, column, word_length, i);
            return false;	
        }
    
        crossboard[row][i] = word[word_index];
        ++word_index;
    }
    return true;
}
bool setVertical(char crossboard[10][10], string word, int row, int column) {
    int word_index = 0;
    int word_length = word.length();

    for (int i=row; i<row+word_length; i++) {
        // if the crossboard has a words we need to check whether it matches with the word
        if (crossboard[i][column] != '-' && crossboard[i][column] != word[word_index]) {
            resetVertical(crossboard, row, column, word_length, i);
            return false;	
        }

        crossboard[i][column] = word[word_index];
        ++word_index;
    }
    return true;
}

bool helperFunc(char crossboard[10][10], vector<string> words, int word_index, int total_words) {
    if (word_index == total_words) {
        return true;
    }
    for (int row=0; row<11-words[word_index].length(); ++row) {
        for (int column=0; column <11-words[word_index].length(); ++column) {
            // check for any place which does not contain +
            if (crossboard[row][column] != '+') {
                if (isValidHorizontal(crossboard, words[word_index], row, column)) {
                    setHorizontal(crossboard, words[word_index], row, column);
                    if (helperFunc(crossboard, words, word_index+1, total_words))
                        return true;
                    else
                        resetHorizontal(crossboard, row, column, words[word_index].length());
                } else if (isValidVertical(crossboard, words[word_index], row, column)) {
                    setVertical(crossboard, words[word_index], row, column);
                    if (helperFunc(crossboard, words, word_index+1, total_words))
                        return true;
                    else
                        resetVertical(crossboard, row, column, words[word_index].length());
                }
            } 
        }
    }
    return false;
}

void algo(char crossboard[][10], string words) {
    vector<string> words_;
    string temp;
    int words_length = words.length();
    for (int i=0; i<words_length; ++i) {
        if (words[i] == ';') {
            words_.push_back(temp);
            temp = "";
            continue;
        }
        temp.push_back(words[i]);
    }
    words_.push_back(temp);
    helperFunc(crossboard, words_, 0, words_.size());
}

int main() {
    char crossboard[][10] ={{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                            {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                            {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
                            {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                            {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                            {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
                            {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
                            {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                            {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                            {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};
    string words = "ICELAND;GWALIOR;FRANCE;AGRA";
    algo(crossboard, words);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << crossboard[i][j];
        }
        cout << endl;
    }
    return 0;
}