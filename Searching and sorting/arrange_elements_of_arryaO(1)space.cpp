#include <bits/stdc++.h>
using namespace std;

void arrange(int arr[], int n) {
    // Your code here
    for (int i=0 ; i<n; i++) {
        arr[i] += arr[arr[i]]%n * n;
    }
    for (int i=0; i<n; i++) {
        arr[i] /= n;
    }
}

int main() {
    int arr[] = {4, 0, 2, 1, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    arrange(arr, size);
    for (auto i: arr) {
        cout << i << ' ';
    }
    return 0;
}