#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> arr) {
    for (int i: arr) {
          cout << i << " ";
    }
    cout << endl;
}
 
int removeDuplicates(vector<int>& arr) {
    int valid_index = 0;
    
    for (int i=1; i<arr.size(); ++i) {
        while (i < arr.size() && arr[i] == arr[valid_index]) {
            ++i;
        }
        if (i < arr.size()) {
            ++valid_index;
            swap(arr[valid_index], arr[i]);
        }
            
    }
    
    return valid_index+1;
}

int main() {
    vector<int> arr{1, 1};
    cout << removeDuplicates(arr) << endl;
    for (int i=0; i<arr.size(); ++i)
        cout << arr[i] << " ";
    return 0;
}