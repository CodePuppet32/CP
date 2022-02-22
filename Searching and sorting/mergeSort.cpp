#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> arr) {
    for (int i: arr) {
          cout << i << " ";
    }
    cout << endl;
}
 
void merge(vector<int>& arr, int beg, int mid, int end) {
	// length of two sorted arrays
	int l1 = mid-beg+1;
	int l2 = end-mid;
	
	// new arrays to copy the sorted array
	vector<int> arr1(l1+1);
	vector<int> arr2(l2+1);
	
	// ace card 
	arr1[l1] = INT_MAX;
	arr2[l2] = INT_MAX;
	
	// copy sorted arrays
	for (int i=beg; i<=mid; ++i) {
		arr1[i-beg] = arr[i];
	}
	for (int i=mid+1; i<=end; ++i) {
		arr2[i-(mid+1)] = arr[i];
	}
	
	int i1=0, i2=0;
	
	for (int i=beg; i<=end; ++i) {
		if (arr1[i1] < arr2[i2]) {
			arr[i] = arr1[i1];
			++i1;
		} else {
			arr[i] = arr2[i2];
			++i2;
		}
	}

}

int main() {
    vector<int> arr{4, 6, 8, 12, 35, 1, 2, 3, 5, 7};
    merge(arr, 0, 4, 9);
    printArr(arr);
    return 0;
}