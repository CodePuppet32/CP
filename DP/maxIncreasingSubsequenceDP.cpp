#include <bits/stdc++.h>
using namespace std;

// we need to consider an element if and only if it is grater than current greatest
// we can either use this and update our greatest or we can skip it


int maxSumIncreasingSubsequence(vector<int>& arr) {
    vector<int> temp;
    vector<int> indices(arr.size());
    indices[0] = -1;

    int maxm = arr[0];
    int maxi = 0;

    temp.push_back(arr[0]);
    for (int i=1; i<arr.size(); ++i) {
        int tmp = arr[i];
        indices[i] = -1;
        for (int j=0; j<i; ++j) {
            if (arr[j] < arr[i]) {
                if (tmp < arr[i]+temp[j]) {
                    indices[i] = j;
                    tmp = max(tmp, arr[i]+temp[j]);
                }
            }
        }
        temp.push_back(tmp);
        if (tmp > maxm) {
            maxm = tmp;
            maxi = i;
        }
        
    }
    vector<int> nums;

    while (maxi != -1) {
        nums.push_back(arr[maxi]);
        maxi = indices[maxi];
    }

    reverse(nums.begin(), nums.end());

    return vector<vector<int>> {vector<int>{maxm}, nums};
}
 
int main() {
    vector<int> arr{8, 12, 2, 3, 15, 5, 7};
    cout << maxSumIncreasingSubsequence(arr);
    return 0;
}