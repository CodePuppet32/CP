#include <bits/stdc++.h>
using namespace std;

bool algo(int arr[], int size) {
    int i = 1;
    for (i; i < size; i++) {
        if (arr[i] != arr[i-1])
            break;
    }
    if (arr[i] > arr[i-1]) {
        while (i < size) {
            if (arr[i] < arr[i-1])
                return false;
            ++i;
        }
    } else {
        while (i < size) {
            if (arr[i] > arr[i-1])
                return false;
            ++i;
        }
    }
    return true;
}

int main() {
    int arr[] = {1, 1, 1, 2, 3, 3, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << algo(arr, size);
    return 0;
}