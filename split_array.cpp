#include <bits/stdc++.h>
using namespace std;

bool algo(int arr[], int size, int group_1, int group_2, int cur_index) {
    // base case
    if (cur_index == size)
        return group_1 == group_2;

    // if element is divisible by 5
    if (arr[cur_index]%5 == 0)
        return algo(arr, size, group_1+arr[cur_index], group_2, cur_index+1);
    else if (arr[cur_index]%3 == 0)     // if element is divisible by 3
        return algo(arr, size, group_1, group_2+arr[cur_index], cur_index+1);
        
    if (algo(arr, size, group_1+arr[cur_index], group_2, cur_index+1)) {
        return true;
    } else {
        return algo(arr, size, group_1, group_2+arr[cur_index], cur_index+1);
    }
}

int main() {
    int arr[] = {1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int group_1, group_2;  
    group_1 = group_2 = 0;
    cout << algo(arr, size, group_1, group_2, 0);
    return 0;
}

