#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> arr) {
    for (int i: arr) {
          cout << i << " ";
    }
    cout << endl;
}
bool hasTwoSumZero(vector<int> &A) {
	int begin = 0, end = A.size()-1;
	
	while (begin < end) {
		int sum = A[begin] + A[end];
		if (sum > 0)
			--end;
		else if(sum < 0)
			++begin;
		else {
            return true;
        }
	}
	
	return false;
}

int main() {
    vector<int> arr{-2, 1, 3, 4};
    cout << hasTwoSumZero(arr);
    return 0;
}

