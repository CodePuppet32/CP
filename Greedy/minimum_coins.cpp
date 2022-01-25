#include <bits/stdc++.h>
using namespace std;

int algo (int arr[], int size, int sum) {
    sort(arr, arr+size, greater<int>());
    int res = 0;

    for (int i = 0; i < size; i++) {
        if (sum >= arr[i]) {
            int c = sum/arr[i];
            res += c;
            sum -= c * arr[i];
        }
        if (sum == 0) break;
    }
    return res;
}

int main() {
    int arr[] = {10, 5, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << algo(arr, size, 52);
    return 0;
}