#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
  vector<vector<int>> res;
	unordered_map<int, vector<int>> map;
	
	for (int i=0; i<tasks.size(); ++i) {
		map[tasks[i]].push_back(i); 
	}

    sort(tasks.begin(), tasks.end());
	
	int beg=0, end=tasks.size()-1;
	
	while(beg < end) {
		int index_beg = map[tasks[beg]].back();
		map[tasks[beg]].pop_back();
		int index_end = map[tasks[end]].back();
		map[tasks[end]].pop_back();
		res.push_back(vector<int>{index_beg, index_end});
		++beg;
		--end;
	}
	
	return res;
}
int main() {
    vector<int> tasks{1, 3, 5, 3, 1, 4};
    vector<vector<int>> res = taskAssignment(3, tasks);

    for (int i=0; i<res.size(); ++i) {
        for (int j=0; j<2; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}