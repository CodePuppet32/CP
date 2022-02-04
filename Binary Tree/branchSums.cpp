#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

void branchSum(Node* root, vector<int>& res, int sum) {
	if (!root->left && !root->right) {
		res.push_back(sum+root->data);
		return;
	}
	if (root->left) branchSum(root->left, res, sum+root->data);
	if (root->right) branchSum(root->right, res, sum+root->data);
}

vector<int> branchSums(Node *root) {
  vector<int> res;
	branchSum(root, res, 0);
	return res;
}


int main() {
    Node* head = new Node(10);
    head->left = new Node(3);
    head->right = new Node(14);
    return 0;
}