#include <bits/stdc++.h>
using namespace std;

int pivot(vector<int>& arr, int beg, int end) {
	int target = arr[beg];
	int i = beg+1;
    int j = end;
	while (1) {
		while (arr[i]<=target)
            ++i;
        while (arr[j]>target)
            --j;
        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
	}
    swap(arr[j], arr[beg]);
    return j;
}

void qSort(vector<int>& arr, int beg, int end) {
	if (beg < end) {
		int piv = pivot(arr, beg, end);
		qSort(arr, beg, piv-1);
		qSort(arr, piv+1, end);
	}
}

void quickSort(vector<int>& array) {
	qSort(array, 0, array.size()-1);
}

int main() {
    vector<int> arr{43, 12, 32, 5, 1, 2, 3, -23, 4, -34};
    quickSort(arr);
    for (auto i: arr) {
        cout << i << " ";
    }
    return 0;
}