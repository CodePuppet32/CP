#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) {
  int begin = 0;
	int end = arr.size()-1;
	
	while (begin<=end) {
		int mid = (begin+end)/2;
		if (arr[mid] == target) {
			return mid;
		} else if(arr[mid] > target)
			end = mid-1;
		else
			begin = mid+1;
	}
  return -1;
}