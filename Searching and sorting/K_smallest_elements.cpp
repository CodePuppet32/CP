#include <bits/stdc++.h>
using namespace std;

int getMaxElement(int arr[], int end) {
    int maxElementIndex = 0;
    for (int i = 1; i < end; i++) {
        if (arr[i] > arr[maxElementIndex]) {
            maxElementIndex = i;
        }
    }
    return maxElementIndex;
}

void algo(int arr[], int size, int k) {
    if (size > k) {
        return;
    }
    
    int maxElementIndex;
    maxElementIndex = getMaxElement(arr, k);

    for (int i=k; i<size; i++) {
        if (arr[i] < arr[maxElementIndex]) {
            swap (arr[i], arr[maxElementIndex]);
            maxElementIndex = getMaxElement(arr, k);
        }
    }
}

int main() {
    int arr[] = {1};
    int size = sizeof(arr)/sizeof(arr[0]);
    algo(arr, size, 2);
    for (int i=0; i<1; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}