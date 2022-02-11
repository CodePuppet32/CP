#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> arr;
    int cur_size;
    int capacity;
    public:
        MinHeap(int capacity) : arr(capacity, -1), cur_size(0), capacity(capacity){}
        int top() {return arr[0];}
        int left(int i) { return (2*i+1);}
        int right(int i) { return (2*i+2);}
        int parent(int i) { return (i-1)/2;}
        int cap() {return capacity;}
        int size() {return cur_size;}
        void printHeap() {for(int i=0; i<cur_size; i++) cout << arr[i] << " ";}
        int getMinimum() {
            if (cur_size)
                return arr[0];
            return INT_MIN;    
        }
        void insert (int data) {
            if (cur_size == capacity) return;
            arr[cur_size++] = data;

            for (int i=cur_size-1; i>0 && arr[i] < arr[parent(i)];) {
                swap (arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }
        void heapify (int index) {
            int left_child = left(index);
            int right_child = right(index);
            int smallest = index;
            if (left_child < cur_size && arr[left_child] < arr[index]) {
                smallest = left_child;
            } else if (right_child < cur_size && arr[right_child] < arr[smallest]) {
                smallest = right_child;
            } 
            if (index != smallest) {
                swap(arr[smallest], arr[index]);
                heapify(smallest);
            }
        }
        int extractMinimum() {
            if (cur_size == 0)
                return INT_MAX;
            int res = arr[0];
            arr[0] = arr[cur_size-1];
            heapify(0);
            --cur_size;
            return res;
        }
};

MinHeap* buildHeap (vector<int>& arr, int capacity) {
    MinHeap* heap = new MinHeap(capacity);
    for (auto element: arr) {
        heap->insert(element);
    } 
    return heap;
}

int main() {
    vector<int> arr{4, 45, 2, 1, 54, 234, 765, 32, 21};
    MinHeap* minHeap = buildHeap(arr, 20);
    cout << minHeap->getMinimum() << endl;
    minHeap->printHeap();
    cout << endl;
    minHeap->extractMinimum();
    minHeap->printHeap();
    cout << endl;
    cout << minHeap->getMinimum();
    return 0;
}