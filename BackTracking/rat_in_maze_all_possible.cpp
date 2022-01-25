#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &matrix, int X, int Y) {
    if (X < 0 || Y < 0 || X >= matrix.size() || Y>= matrix[0].size())
        return false;
    return matrix[X][Y] == 1;
}

void helperFunc(vector<vector<int>> &matrix, vector<vector<int>> &visited, vector<string> &result, string &till_now, int cX, int cY, int n) {
    // base case when we are at n-1, n-1
    if (cX == n-1 && cY == n-1) {
        result.push_back(till_now);
        visited[cX][cY] = 0;
        return;
    }
    if (visited[cX][cY] == 1)
        return;
    
    visited[cX][cY] = 1;
    
    if (isValid(matrix, cX, cY+1)) {
        till_now.push_back('R');
        helperFunc(matrix, visited, result, till_now, cX, cY+1, n);
        till_now.pop_back();
    }
    
    if (isValid(matrix, cX+1, cY)) {
        till_now.push_back('D');
        helperFunc(matrix, visited, result, till_now, cX+1, cY, n);
        till_now.pop_back();        
    }

    if (isValid(matrix, cX-1, cY)) {
        till_now.push_back('U');
        helperFunc(matrix, visited, result, till_now, cX-1, cY, n);
        till_now.pop_back();
    }

    if (isValid(matrix, cX, cY-1)) {
        till_now.push_back('L');
        helperFunc(matrix, visited, result, till_now, cX, cY-1, n);
        till_now.pop_back();
    }
    visited[cX][cY] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> result;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    string till_now = "";
    helperFunc(m, visited, result, till_now, 0, 0, n);
    return result;
}

int main() {
    vector<vector<int>> matrix {{0, 1, 1, 1}, 
                                {1, 1, 1, 0}, 
                                {1, 0, 1, 1}, 
                                {0, 0, 1, 1}};
    int n = 4;
    vector<string> res;
    res = findPath(matrix, n);
    for (auto i: res)
        cout << i << "\n";
    return 0;
}