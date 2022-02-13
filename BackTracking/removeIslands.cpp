#include <bits/stdc++.h>
using namespace std;

bool isConnected(vector<vector<int>>& arr, int row, int column, vector<vector<int>>& hasVisited) {
    // if we get pass the perimeter
	if (row == 0 || column == 0 || row == arr.size()-1 || column == arr[0].size()-1) return arr[row][column];
    // if we encounter 0
    if (arr[row][column] == 0) return false;
    // checking upward
    if (!hasVisited[row-1][column]) {
        hasVisited[row-1][column] = true;
        if (isConnected(arr, row-1, column, hasVisited)) {
            hasVisited[row-1][column] = false;
            return true;
        }
        hasVisited[row-1][column] = false;
    } 
    if (!hasVisited[row+1][column]) {   // checking downward
        hasVisited[row+1][column] = true;
        if(isConnected(arr, row+1, column, hasVisited)) {
            hasVisited[row+1][column] = false;
            return true;
        }
        hasVisited[row+1][column] = false;
    } 
    if (!hasVisited[row][column+1]) {   // checking forward
        hasVisited[row][column+1] = true;
        if(isConnected(arr, row, column+1, hasVisited)) {
            hasVisited[row][column+1] = false;
            return true;
        }
        hasVisited[row][column+1] = false;
    }  
    if (!hasVisited[row][column-1]) {   // checking forward
        hasVisited[row][column-1] = true;
        if(isConnected(arr, row, column-1, hasVisited)) {
            hasVisited[row][column-1] = false;
            return true;
        }
        hasVisited[row][column-1] = false;
    }
    return false;
}



vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
    vector<vector<int>> hasVisited(matrix.size(), vector<int>(matrix[0].size(), false));
    for (int i=1; i<matrix.size()-1; ++i) {
            for (int j=1; j<matrix[0].size()-1; ++j) {
                if (matrix[i][j] && !isConnected(matrix, i, j, hasVisited)) {
                    matrix[i][j] = 0;
                }
            }
        }
    return matrix;
}


int main() {
    vector<vector<int>> matrix = {
                                    {1, 0, 0, 0, 0, 0},
                                    {0, 1, 0, 1, 1, 1},
                                    {0, 0, 1, 0, 1, 0},
                                    {1, 1, 0, 0, 1, 0},
                                    {1, 0, 1, 1, 0, 0},
                                    {1, 0, 0, 0, 0, 1}
                                };
    matrix = removeIslands(matrix);
    for (int i=0; i<matrix.size(); ++i) {
        for (int j=0; j<matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}