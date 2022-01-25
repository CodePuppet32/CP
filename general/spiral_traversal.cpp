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
        if (top <= bottom) {
            for (int column=right-1; column >= left; --column) {
                cout << matrix[bottom][column] << " ";
            }
            --bottom;
            for (int row=bottom-1; row > top; --row) {
                cout << matrix[row][left] << " ";
            }
            ++left;
        }
    }
}

int main() {
    vector<vector<int>> matrix{{1, 2, 3, 4, 5}, 
                               {5, 6, 7, 8, 6}, 
                               {9, 10, 11, 12, 7}};
    algo(matrix);
    return 0;
}