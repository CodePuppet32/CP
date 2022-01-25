#include <bits/stdc++.h>
using namespace std;

int algo(int arr[], int size) {
    int res = 0;
    // peak must atleast be 3 length
    int cur_peak_length = 3;

    // traverse and check if we have a peak
    for (int i = 1; i < size-1; i++) {
        // if current element is grater than left and right element
        if (arr[i] > arr[i - 1] && arr[i] > arr[i+1]) {
            int search = i-1;
            // traverse in left direction and check how long has it been increasing
            while (search >= 0 && arr[search] > arr[search-1]) {
                ++cur_peak_length;
                --search;
            }
            search = i+1;
            // traverse in right direction and check how long does it decrease
            while (search < size+1 && arr[search] > arr[search+1]) {
                ++cur_peak_length;
                ++search;
            }
            // if current peak is greater than previous peak -> update result
            res = max(res, cur_peak_length);
            // reset the peak size
            cur_peak_length = 3;
            // also some optimization
            i = search;
        }
    }
    return res;
}

int main() {
    int arr[] = {1, 2, 3, 4, 10, 9, 5, 2, 1, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << algo(arr, size);
    return 0;
}