#include <bits/stdc++.h>
using namespace std;

int algo(int arr[], int dep[], int size) {
    int res = 0;
    int maxm = 0;
    // sort the departure array
    sort(dep, dep+size);

    int i, j;
    i = j = 0;

    while(i < size) {
        // if there is arrival before departure
        if(arr[i] == dep[j]) {
            i++;
            j--;
        }
        else if(arr[i] < dep[j]) {
            res++;
            i++;
        }
        // if there is departure before arrival
        else {
            res--;
            j++;
        }
        maxm = max(maxm, res);
    }

    return maxm;
}

int main() {
    int arr[] = {900, 940, 950, 1100, 1130, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1200, 1900, 2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << algo(arr, dep, n);
    return 0;
}

