#include <bits/stdc++.h>
using namespace std;

int algo(int arr[], int size) {
    int leftMax, rightMax;
    leftMax = rightMax = 0;
    int left, right;
    left = 0;
    right = size-1;
    int res = 0;

    while (left < right) {
        if(arr[left] < arr[right]) {    
            if(arr[left] > leftMax) leftMax = arr[left];
            else res += (leftMax - arr[left]);
            left++;
        } else {
            if (arr[right] > rightMax) rightMax = arr[right];
            else res += (rightMax - arr[right]);
            right--;
        }
    }
    return res;
}

int main() {
    int arr[] = {4, 2, 0, 3, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << algo(arr, n);
    return 0;
}

