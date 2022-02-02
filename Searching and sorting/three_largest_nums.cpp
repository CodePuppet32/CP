#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
  vector<int> res(3, INT_MIN);
	
	for (auto num: array) {
		if (num > res[2]) {
			res[0] = res[1];
			res[1] = res[2];
			res[2] = num;
		} else if(num > res[1]) {
			res[0] = res[1];
			res[1] = num; 
		} else if(num > res[0]) {
			res[0] = num;
		}
	}
  return res;
}
