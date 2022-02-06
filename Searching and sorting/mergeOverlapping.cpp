#include <bits/stdc++.h>
using namespace std;

void printVect(vector<vector<int>>& res) {
	for (int i=0; i<res.size(); ++i) {
        cout << '[' << res[i][0] << "," << res[i][1] << "]" << endl;
    }
	cout << endl;
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
	sort(intervals.begin(), intervals.end());
	
	for (int i=0; i<intervals.size(); ++i) {
		// if we are checking the last interval or the current interval doesnt overlap
		if (i == intervals.size()-1 || intervals[i][1] < intervals[i+1][0]) {
			res.push_back(intervals[i]);
		} else {
			int begin_time = intervals[i][0];
			int end_time = intervals[i][1];
			++i;
			while (i < intervals.size() && end_time >= intervals[i][0]) {
				end_time = max(end_time, intervals[i][1]);
				++i;
			}
			res.push_back(vector<int>{begin_time, end_time});
			--i;
		}
	}
	return res;
}

int main() {
    vector<vector<int>> intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    vector<vector<int>> res = mergeOverlappingIntervals(intervals);
    printVect(res);
    return 0;
}