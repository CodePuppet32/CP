#include <bits/stdc++.h>
using namespace std;

int qSort(int arr[], int beg, int end) {
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

void algo(int arr[], int beg, int end) {
  if (beg < end) {
    int pivot = qSort(arr, beg, end);
    algo(arr, beg, pivot-1);
    algo(arr, pivot+1, end);
  }
}

int main() {
    int arr[] = {34, 45, 234, 234, 54, 324, 65, 23, 234 , 54};
    int size = sizeof(arr)/sizeof(arr[0]);
    algo(arr, 0, size-1);
    for (int i = 0; i < size; i++) {
      cout << arr[i] << ' ';
    }
    return 0;
}

