#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

bool helperFunc(queue<Node*> q) {
	vector<int> arr;
	while (!q.empty()) {
		arr.push_back(q.front()->data);
		q.pop();
	}

	int begin = 0, end = arr.size()-1;
	while (begin < end)
		if (arr[begin++] != arr[end--])
			return false;
	return true;
}

bool isSymmetric(Node* root) {
    queue<Node*> q;
	q.push(root);
	
	while (!q.empty()) {
		if (!helperFunc(q))
			return false;
		int count = q.size();
		for (int i=0; i<count; ++i) {
			Node* temp = q.front();
			q.pop();
			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
		}
	}
	return true;
}


int main() {
    Node* head = new Node(6);
    head->left = new Node(4);
    head->right = new Node(4);
    head->left->left = new Node(-1);
    head->left->right = new Node(2);
    // head->left->right->left = new Node(2);
    // head->left->right->right = new Node(20);

    head->right->left = new Node(2);
    head->right->right = new Node(-1);
    // head->right->right->right = new Node(1);

    cout << isSymmetric(head);
    return 0;
}