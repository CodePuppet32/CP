#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

int maxInBT(Node* head) {
    if (!head) return INT_MIN;
    return max(max(head->data, maxInBT(head->left)), maxInBT(head->right));
}


int main() {
    Node* head = new Node(10);
    head->left = new Node(3);
    head->right = new Node(14);
    cout << maxInBT(head) << endl;
    return 0;
}