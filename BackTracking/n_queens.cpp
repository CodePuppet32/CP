#include <bits/stdc++.h>
using namespace std;

vector<int> isUsed(100, 0);

bool isValid(vector<vector<bool>> &matrix, int x, int y) {
    for (int column = 0; column < y; ++column) {
        if (matrix[x][column])
            return false;
    }
    for (int row=x-1, column=y-1; row >= 0 && column >= 0; --row, --column) {
        if (matrix[row][column])
            return false;
    }
    for (int row=x+1, column=y-1; row < matrix.size() && column >= 0; ++row, --column) {
        if (matrix[row][column])
            return false;
    }
    return true;
}

bool algo(vector<vector<bool>> &matrix, int n, int current_col=0) {
    if (current_col == n) return true;
    for (int row = 0; row < matrix.size(); ++row) {
        if (isValid(matrix, row, current_col) && !isUsed[row]) {
            matrix[row][current_col] = true;
            isUsed[row] = 1;
            if (algo(matrix, n, current_col+1))
                return true;
            matrix[row][current_col] = false;
            isUsed[row] = 0;
        }
    }
    return false;
}

int main() {
    int n = 29;
    vector<vector<bool>> matrix(n, vector<bool>(n, false));
    algo(matrix, n);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}