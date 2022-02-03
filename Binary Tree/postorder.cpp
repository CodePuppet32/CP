#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

void post(Node* root, vector<int> &res) {
    if (!root) return;
    post(root->left, res);
    post(root->right, res);
    res.push_back(root->data);
}

//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
    vector<int> res;
    post(root, res);
    return res;
  // Your code here
}


int main() {
    Node* head = new Node(10);
    head->left = new Node(3);
    head->right = new Node(14);
    return 0;
}