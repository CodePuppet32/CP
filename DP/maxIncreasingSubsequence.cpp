#include <bits/stdc++.h>
using namespace std;

// we need to consider an element if and only if it is grater than current greatest
// we can either use this and update our greatest or we can skip it

int helperFunc(vector<int> arr, int cur_index, int cur_sum, int greatest) {
    if (arr.size() == cur_index) return cur_sum;

    // we have following choices ->
    // we can skip this element no matter if it is smaller than current element or greater
    // we can start new recursion no matter if it is smaller than current element or greater
    // if current element is greater than greatest then we can use this in previous recursion
    
    // skip this element
    int skipped = helperFunc(arr, cur_index+1, cur_sum, greatest);
    // start new recursion
    int new_rec = helperFunc(arr, cur_index+1, arr[cur_index], arr[cur_index]);
    // if cur element is greater than greatest continue previous recursion
    int pre_rec = INT_MIN;
    if (arr[cur_index] > greatest)
        pre_rec = helperFunc(arr, cur_index+1, cur_sum+arr[cur_index], arr[cur_index]);
    
    return max(max(skipped, new_rec), pre_rec);
}

int maxSumIncreasingSubsequence(vector<int>& arr) {
    return helperFunc(arr, 1, arr[0], arr[0]);
     
}
 
int main() {
    vector<int> arr{10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << maxSumIncreasingSubsequence(arr);
    return 0;
}