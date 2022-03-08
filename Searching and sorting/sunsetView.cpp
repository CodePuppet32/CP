#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> arr) {
    for (int i: arr) {
          cout << i << " ";
    }
    cout << endl;
}

vector<int> sunset_view_east(vector<int>& arr) {
    vector<int> res;
    res.push_back(arr.size()-1);
    int largest_so_far = arr.back();

    for (int i=arr.size()-2; i >= 0; --i) {
        if (arr[i] > largest_so_far) {
            largest_so_far = arr[i];
            res.push_back(i);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> sunset_view_west(vector<int>& arr) {
    vector<int> res;
    res.push_back(0);
    int largest_so_far = arr[0];

    for (int i=1; i<arr.size(); ++i) {
        if (arr[i] > largest_so_far) {
            largest_so_far = arr[i];
            res.push_back(i);
        }
    }
    return res;
}
 
vector<int> sunset_view(vector<int>& arr, string direction) {
    if (direction == "EAST")
        return sunset_view_east(arr);
    return sunset_view_west(arr);
}

int main() {
    vector<int> arr{3, 5, 4, 4, 3, 1, 3, 2};
    string direction = "WEST";
    vector<int> res = sunset_view(arr, direction);
    printArr(res);
    return 0;
}