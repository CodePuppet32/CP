#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
	vector<vector<int>> res;
	
	for (int i=0; i<matrix[0].size(); ++i) {
		vector<int> temp;
		for (int j=0; j<matrix.size(); ++j) {
			temp.push_back(matrix[j][i]);
		}
		res.push_back(temp);
	}	
	return res;
}

void reverseArray(vector<int>& arr) {
	int beg = 0, end = arr.size()-1;
	while (beg < end) {
		swap(arr[beg], arr[end]);
		++beg;
		--end;
	}
}

vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix){
    matrix = transposeMatrix(matrix);
	
	for (int i=0; i<matrix.size(); ++i) {
		reverseArray(matrix[i]);
	}
	return matrix;
}

int main() {
    return 0;
}