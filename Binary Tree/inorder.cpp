#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};
void inorder(Node* root, vector<int>& res) {
        if (!root)
        return;
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }


int main() {
    Node* head = new Node(10);
    head->left = new Node(3);
    head->right = new Node(14);
    return 0;
}