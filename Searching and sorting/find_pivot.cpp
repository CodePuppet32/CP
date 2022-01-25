#include <bits/stdc++.h>
using namespace std;

int algo(int arr[], int end) {
    int begin = 0;
    --end;

    while(begin <= end) {
        int mid = (begin + end ) / 2;
        cout << begin << " " << end << " " << mid << '\n';
        if (arr[mid] < arr[mid-1]) {
            return mid;
        } else if(arr[mid] > arr[begin]) {
            begin = mid;
        } else {
            end = mid;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 20, 40, 30, 20, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << algo(arr, n);
    return 0;
}

