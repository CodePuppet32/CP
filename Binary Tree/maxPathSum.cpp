#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

int helperFunc(Node* node, int& res) {
    if (!node) return 0;
    
    int ls = helperFunc(node->left, res);
    int rs = helperFunc(node->right, res);
    // current = 5
    // left = -1
    // right = 6, -2
    int current_max = node->data + max(ls+rs, max(ls, rs));
    res = max(current_max, res);
    return node->data + max(rs, ls);
}

int maxPathSum(Node* head) {
    int res = INT_MIN;
    helperFunc(head, res);
    return res;
}


int main() {
    Node* head = new Node(10);
    head->left = new Node(15);
    head->right = new Node(8);
    head->left->left = new Node(3);
    head->left->right = new Node(4);
    head->left->right->left = new Node(5);
    head->left->right->right = new Node(20);

    head->right->right = new Node(6);
    head->right->right->left = new Node(2);
    head->right->right->right = new Node(1);

    cout << maxPathSum(head) << endl;
    return 0;
}