#include <bits/stdc++.h>
using namespace std;

int algo(int arr[], int end) {
    // we need to find the peak element
    int begin = 0;

    while(begin <= end) {
        int mid = (begin + end )/2;
        if((mid == 0 || arr[mid] >= arr[mid-1]) && (mid == end || arr[mid] >= arr[mid+1])) {
            return mid;
        } else if(mid > 0 && arr[mid] <= arr[mid-1]) {
            end = mid - 1;
        } else{
            begin = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {30, 0, 10, 20, 50, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << algo(arr, n-1);
    return 0;
}

