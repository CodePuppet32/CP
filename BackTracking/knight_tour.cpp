#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &matrix, int row, int column) {
    if (row >= matrix.size() || column >= matrix[0].size() && matrix[row][column])
        return false;
    return true;
}

// where can a knight move?
// column+1, row+2 column+1, row-2
// column-1, row+2 column-1, row-2
// column+2, row-1 column+2, row+1
// column-2, row-1 column-2, row+1

bool algo(vector<vector<int>> &matrix, int current_move, int row=0, int column=0) {
    if (isValid(matrix, row+2, column+1)) {
        matrix[row+2][column+1] = current_move+1;
        if (algo(matrix, current_move+1, row+2, column+1))
            return true;
        matrix[row+2][column+1] = 0;
    } else if (isValid(matrix, row+2, column-1)) {
        matrix[row+2][column-1] = current_move+1;
        if (algo(matrix, current_move+1, row+2, column-1))
            return true;
        matrix[row+2][column-1] = 0;
    } else if (isValid(matrix, row-2, column-1)) {
        matrix[row-2][column-1] = current_move+1;
        if (algo(matrix, current_move+1, row-2, column-1))
            return true;
        matrix[row-2][column-1] = 0;
    } else if (isValid(matrix, row-2, column+1)) {
        matrix[row-2][column+1] = current_move+1;
        if (algo(matrix, current_move+1, row-2, column+1))
            return true;
        matrix[row-2][column+1] = 0;
    } else if (isValid(matrix, row-1, column+2)) {
        matrix[row-1][column+2] = current_move+1;
        if (algo(matrix, current_move+1, row-1, column+2))
            return true;
        matrix[row-1][column+2] = 0;
    } else if (isValid(matrix, row-1, column-2)) {
        matrix[row-1][column-2] = current_move+1;
        if (algo(matrix, current_move+1, row-1, column-2))
            return true;
        matrix[row-1][column-2] = 0;
    } else if (isValid(matrix, row+1, column-2)) {
        matrix[row+1][column-2] = current_move+1;
        if (algo(matrix, current_move+1, row+1, column-2))
            return true;
        matrix[row+1][column-2] = 0;
    } else if (isValid(matrix, row+1, column+2)) {
        matrix[row+1][column+2] = current_move+1;
        if (algo(matrix, current_move+1, row+1, column+2))
            return true;
        matrix[row+1][column+2] = 0;
    }
    return false;
}

int main() {
    int n = 29;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    algo(matrix, 0);
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}