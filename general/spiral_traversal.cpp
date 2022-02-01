#include <bits/stdc++.h>
using namespace std;

void algo(vector<vector<int>> matrix) {
    int top, bottom, left, right;
    top = left = 0;
    bottom = matrix.size() - 1;
    right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) { 
        for (int column=left; column <= right; ++column) {
            cout << matrix[top][column] << " ";
        }
        ++top;
        for (int row=top; row <= bottom; ++row) {
            cout << matrix[row][right] << " ";
        }
        --right;
        if (top <= bottom && left <= right) {
            for (int column=right; column >= left; --column) {
                cout << matrix[bottom][column] << " ";
            }
            --bottom;
            for (int row=bottom; row >= top; --row) {
                cout << matrix[row][left] << " ";
            }
            ++left;
        }
    }
}

int main() {
    vector<vector<int>> matrix{{1, 2, 3},
                               {12, 13, 4}, 
                               {11, 14, 5}, 
                               {10, 15, 6}, 
                               {9, 8, 7}};
    algo(matrix);
    return 0;
}