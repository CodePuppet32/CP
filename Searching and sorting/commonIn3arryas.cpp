#include <bits/stdc++.h>
using namespace std;

void algo(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    int size1 = arr1.size(), size2 = arr2.size(), size3 = arr3.size();
    int index1 = 0, index2 = 0, index3 = 0;

    while (index1 < size1 && index2 < size2 && index3 < size3) {
        // if all three array contains the same element
        if (arr1[index1] == arr2[index2] && arr1[index1] == arr3[index3]) {
           cout <<  arr1[index1] << " ";
           ++index1; ++index2; ++index3;
        } 
        int max_of_three = max(arr1[index1], max(arr2[index2], arr3[index3]));

        if (arr1[index1] < max_of_three) ++index1;
        if (arr2[index2] < max_of_three) ++index2;
        if (arr3[index3] < max_of_three) ++index3;
    }

}

int main() {
    vector<int> arr1{1, 5, 10, 20, 40, 80};
    vector<int> arr2{6, 7, 20, 80, 100};
    vector<int> arr3{3, 4, 15, 20, 30, 70, 80, 120};
    algo(arr1, arr2, arr3);
    return 0;
}