#include <bits/stdc++.h>
using namespace std;

//void qsort()

int algo(int length, int breadth) {
    if(length <= 0 || breadth <= 0) {
        return 0;
    }

    // base case when either of the side is twice the other
    if(length == breadth) return length;

    if(length == 2*breadth || breadth == 2*length) {
        return min(length, breadth);
    }

    // recursive case -> cut the bigger side as many time we can of same length as the smaller side
    if(length < breadth) {
        return algo(length, breadth%length);
    } else {
        return algo(length%breadth, breadth);
    }
}

int main() {
    //int arr[] = {8, 5, 2, 9, 5, 6, 3};
    //int size = sizeof(arr)/sizeof(arr[0]);
    int length, breadth;
    length = 9847598;
    breadth = 42348;
    cout << algo(length, breadth); 
    
    return 0;
}

