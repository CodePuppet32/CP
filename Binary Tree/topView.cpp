#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

int leftMost(Node* root, int current_lvl = 0) {
	if (!root) return current_lvl+1;
	int left = leftMost(root->left, current_lvl-1);
	int right = leftMost(root->right, current_lvl+1);
	return min(left, right);
}

int rightMost(Node* root, int current_lvl = 0) {
	if (!root) return current_lvl-1;
	int left = rightMost(root->left, current_lvl-1);
	int right = rightMost(root->right, current_lvl+1);
	return max(left, right);
}

void tv(Node* root, vector<int> &hasAlready, int current_lvl) {
    if (!root) return;
    if (!hasAlready[current_lvl])
        hasAlready[current_lvl] = root->data;
    tv(root->left, hasAlready, current_lvl-1);
    tv(root->right, hasAlready, current_lvl+1);
}

vector<int> topView(Node* root) {
    int left = leftMost(root);
    int right = rightMost(root);
    vector<int> hasAlready(left+right+1);
    fill(hasAlready.begin(), hasAlready.end(), 0);
    tv(root, hasAlready, left);
    return hasAlready;
}

int main() {
    Node* head = new Node(10);
    head->left = new Node(15);
    head->right = new Node(8);
    head->left->left = new Node(3);
    head->left->right = new Node(4);
    head->left->right->left = new Node(2);
    head->left->right->right = new Node(20);

    head->right->right = new Node(6);
    head->right->right->left = new Node(2);
    head->right->right->right = new Node(1);
    vector<int> res = topView(head);
    for (auto i: res) cout << i << " ";
    return 0;
}