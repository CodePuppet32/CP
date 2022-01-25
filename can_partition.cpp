#include <bits/stdc++.h>
using namespace std;

bool helperFunc(vector<int> &nums, int g1, int g2, int cur_index, int sum) {
    cout << cur_index << endl;
    if (cur_index == nums.size())
        return g1 == g2;
    
    if ((g1/2 < sum) && helperFunc(nums, g1+nums[cur_index], g2, cur_index+1, sum)) {
        return true;
    } else 
        return helperFunc(nums, g1, g2+nums[cur_index], cur_index+1, sum);
}

bool canPartition(vector<int>& nums) {
    int g1, g2;
    g1 = g2 = 0;
    int sum = 0;
    for (int i=0; i<nums.size(); i++)
        sum += nums[i];
    if (sum%2 != 0) return false;
    return helperFunc(nums, g1, g2, 0, sum);
}

int main() {
    vector<int> nums{100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97};
    cout << canPartition(nums);
    return 0;
}