#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr) {
    for (auto i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

int pivot(vector<int> &arr, int piv_index) {
	int target = arr[piv_index];
	swap(arr[piv_index], arr[0]);
	
	int i=1, j=arr.size()-1;
	
	while (1) {
		while (arr[i] <= target)
			++i;
		while (arr[j] > target)
			--j;
		if (i < j)
			swap(arr[i], arr[j]);
		else
			break;
	}
	swap(arr[j], arr[0]);
	return j;
}

int getKthLargestElement(vector<int> &list, int k) {
		k = list.size()-k;
		int piv_index = 0;
		while (1) {
			piv_index = pivot(list, piv_index);
			if (piv_index == k) return list[k];
			if (k > piv_index) piv_index+=1;
			else piv_index -= 1;
		}
}
// 0, -2, 4, 6, 12, 22, 23, 43
int main() {
    vector<int> arr{2, 1};
    cout << getKthLargestElement(arr, 1);
    return 0;
}