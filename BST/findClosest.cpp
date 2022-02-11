#include <bits/stdc++.h>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) : value(value){}
};

int findClosestValueInBst(BST *tree, int target) {
	int res = INT_MAX;
	
	while (tree) {
		if (tree->value == res) return res;
		if (res == INT_MAX || abs(tree->value - target) < abs(res-target))
			res = tree->value;
		if (tree->value > target)
			tree = tree->left;
		else
			tree = tree->right;
	}
	
	return res;
}

int main() {
    BST* head = new BST(100);
    head->left = new BST(5);
    head->left->right = new BST(15);
    head->left->right->left = new BST(5);
    head->left->right->right = new BST(22);
    head->left->right->right->right = new BST(57);
    head->left->right->right->right->right = new BST(60);
    head->left->left = new BST(2);
    head->left->left->right = new BST(3);
    head->left->left->left = new BST(1);
    head->left->left->left->right = new BST(1);
    head->left->left->left->right->right = new BST(1);
    head->left->left->left->right->right->right = new BST(1);
    head->left->left->left->right->right->right->right = new BST(1);
    head->left->left->left->left = new BST(-51);
    head->left->left->left->left->left = new BST(-403);
    head->right = new BST(502);
    head->right->left = new BST(204);
    head->right->left->left = new BST(203);
    head->right->left->right = new BST(205);
    head->right->left->right->right = new BST(207);
    head->right->left->right->right->right = new BST(208);
    head->right->left->right->right->left = new BST(206);
    head->right->right = new BST(55000);
    head->right->right->left = new BST(1001);
    head->right->right->left->right = new BST(4500);

    cout << findClosestValueInBst(head, -1);

    return 0;
}