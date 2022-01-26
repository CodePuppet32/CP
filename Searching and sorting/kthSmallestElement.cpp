// all the values are distinct !!

#include <bits/stdc++.h>
using namespace std;

int getPivotPosition(int arr[], int beg, int end) {
    int i, j;
    i = j = beg;

    // scan all the elements except the last one
    while (j < end) {
      // if we encounter a smaller element than our pivot we want to swap it with i
      if (arr[j] < arr[end]) {
        // search for a greater element than jth and swap
        while (i < j && arr[i] < arr[end]) {
          ++i;
        }
        swap(arr[j], arr[i]);
        ++i;
      }
      ++j;
    }
    swap(arr[end], arr[i]);
    return i;
}

int algo(int arr[], int size, int k) {
    int beg = 0, end = size - 1;

    while (beg <= end) {
        // get the pivot position of the pivot
        int pivot_position = getPivotPosition(arr, beg, end);

        if (pivot_position == k-1) {
            return arr[pivot_position];
        }
        // if the pivot position is less than k-1 -> we need to search in pivot_position+1 to end position
        if (pivot_position < k-1) {
            beg = pivot_position + 1;
        } else {
            end = pivot_position - 1;
        }
    }
    return -1;
}
// 2 3 4 7 12 15 34 43
int main() {
    int arr[] = {2, 4, 34, 43, 15, 7, 3, 12};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << algo(arr, size, 10);
    return 0;
}