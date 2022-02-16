#include <bits/stdc++.h>
using namespace std;

int pivot(vector<int> &arr, int beg, int end) {
    int pivot = arr[beg];
    int l=beg-1, h=end+1;
    while (l<h) {
        do {
            ++l;
        } while(pivot < arr[l]);
        do {
            --h;
        } while(pivot > arr[h]);
        if (l >= h) return h;
        swap(arr[l], arr[h]);
    }
}

void quickSort(vector<int> &arr, int begin, int end) {
    if (begin < end) {
        int piv = pivot(arr, begin, end); 
        quickSort(arr, begin, piv);
        quickSort(arr, piv+1, end);
    }
}

int main() {
    vector<int> arr{-4, 5, 10, 8, -10, -6, -4, -2, -5, 3, 5, -4, -5, -1, 1, 6, -7, -6, -7, 8};
    // quickSort(arr, 0, arr.size()-1);
	cout << pivot(arr, 0, arr.size()-1);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}
