#include <bits/stdc++.h>
using namespace std;


bool algo(vector<vector<bool>> maze, int fX, int fY, int X=0, int Y=0) {
    /* The idea is to keep moving in the right direction until we have reached the fYth column or we hit a wall 
       If we hit a wall or we encounter Y>fY we can backtrack */
    
    cout << X << " " << Y << endl;

    if (X == fX && Y == fY) {
        return true;
    }

    /* 0 0 1 0
       0 0 1 0
       1 0 1 0
       0 0 1 0*/

    if (X > fX || Y > fY || maze[X][Y] == 1) {
        return false;
    } 

    if (algo(maze, fX, fY, X, Y+1)){
        return true;
    } else if(algo(maze, fX, fY, X+1, Y)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    vector<vector<bool>> maze {{0, 0, 1, 0}, {0, 0, 1, 0}, {1, 0, 1, 0}, {1, 0, 1, 0}};
    cout << algo(maze, 3, 3);
    return 0;
}

