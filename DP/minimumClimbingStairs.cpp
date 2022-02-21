#include <bits/stdc++.h>
using namespace std;
 
int helperFunc(vector<int>& arr, int spent, int cur_index) {
    if (cur_index >= arr.size()) {
        return spent;
    }
    int one_jump = helperFunc(arr, spent+arr[cur_index+1], cur_index+1);
    int two_jump = helperFunc(arr, spent+arr[cur_index+2], cur_index+2);
    
    return min(one_jump, two_jump);
}

int minCostClimbingStairs(vector<int>& cost) {
    return helperFunc(cost, 0, -1);
}

int main() {
    vector<int> cost{10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}