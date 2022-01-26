#include <bits/stdc++.h>
using namespace std;

int algo(int arr[], int size, int num_cows) {
    sort(arr, arr+size);

    int max_distance = arr[size-1] - arr[0];
    int min_distance = 0;

    // using binary search
    while (min_distance <= max_distance) {
        int mid_distance = (min_distance + max_distance)/2;
        // for every distance check if we can place cows in that configuration
        //1 2 4 8 9
        int temp_cows = num_cows-1;
        // to keep track of previousaly placed cow
        int prev_placed = arr[0];
        for (int i=1; i<size; i++) {
            // if now cow is left to place break the loop
            if (!temp_cows)
                break;
            // if we have some cows to place and the distance between this stall and previous is greater or equal to the distance
            if ((arr[i]-prev_placed) >= mid_distance) {
                // update the previous placed cow position
                prev_placed = arr[i];
                --temp_cows;
            }
        }
        if (temp_cows == 0)
            min_distance = mid_distance+1;
        else
            max_distance = mid_distance-1;
    }

    return min_distance-1;
}

int main() {
    int arr[] = {1, 334, 34, 54, 23, 43};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << algo(arr, size, 6);
    return 0;
}