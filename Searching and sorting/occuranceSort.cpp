#include <bits/stdc++.h>
using namespace std;
 
int getMaxIndex(vector<int>& map) {
    int maxm = 0;
    for (int i=1; i<10; ++i) {
        if (map[i] > map[maxm])
            maxm = i;
    }
    return maxm;
}

void occuranceSort(vector<int>& arr) {
    vector<int> map(10, 0);

    for (int i: arr)
        ++map[i];
    
    while (1) {
        int maxIndex = getMaxIndex(map);
        if (map[maxIndex] == 0)
            break;
        for (int i=0; i<map[maxIndex]; ++i)
            cout << maxIndex << " ";
        map[maxIndex] = 0;
    }
}

int main() {
    vector<int> arr{1, 1, 0, 0, 2, 1, 0, 2, 2, 0, 4, 4, 4, 4, 5, 5, 3, 2, 5, 5, 5, 6, 5};
    occuranceSort(arr);
    return 0;
}