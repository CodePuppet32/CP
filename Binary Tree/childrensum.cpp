#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

int isSumProperty(Node *root) {
        if (root == NULL || (!root->left && !root->right)) return 1;
        int left_data = root->left? root->left->data: 0;
        int right_data = root->right? root->right->data: 0;
        return (root->data == (left_data + right_data) &&
                isSumProperty(root->left) && 
                isSumProperty(root->right));
    }

int main() {
    Node* head = new Node(10);
    head->left = new Node(3);
    head->right = new Node(14);
    return 0;
}