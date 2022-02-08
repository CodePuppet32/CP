#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void algo(int arr[], int size) {
    int scanner=0;
    int begin=0;
    int end = size-1;

    while (scanner <= end) {
        if (arr[scanner] == 0) {
            while (begin <= scanner && arr[begin] == 0) ++begin;
            swap (arr[begin], arr[scanner]);
            ++begin;
        } else if (arr[scanner] == 1) {
            ++scanner;
        } else {
            while (end >= scanner && arr[end] == 2) --end;
            swap (arr[end], arr[scanner]);
            --end;
        }
    }
}

int main() {
    int arr[] = {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    algo(arr, size);
    printArray(arr, size);
    return 0;
}