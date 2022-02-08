#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

int helperFunc(Node* node, int &maxm) {
    if (!node) return 0;
    int lh = helperFunc(node->left, maxm);
    int rh = helperFunc(node->right, maxm);
    
    maxm = max(maxm, lh+rh);
    return 1+max(lh, rh);
}

int diameter(Node* head) {
    int maxm;
    helperFunc(head, maxm);
    return maxm;
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

    cout << diameter(head) << endl;
    return 0;
}