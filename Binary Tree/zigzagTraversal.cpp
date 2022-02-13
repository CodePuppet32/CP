#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

vector<int> zigzagLevelOrderTraversal(Node* root) {
    vector<int> res;
	bool rotate = false;
	
	queue<Node*> q;
	q.push(root);
	
	while (!q.empty()) {
		// count the number of elements  in the queue
		int count = q.size();
		stack<int> s;
		for (int i=0; i<count; ++i) {
			Node* temp = q.front();
			q.pop();
			
			if (rotate)
				s.push(temp->data);
		    else
				res.push_back(temp->data);
			
			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
		}
		if (rotate) {
			rotate = false;
			while (!s.empty()) {
				res.push_back(s.top());
				s.pop();
			}
		} else {
			rotate = true;
		}
	}
	
	return res;
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
    vector<int> res = zigzagLevelOrderTraversal(head);
    for (auto i: res) cout << i << " ";
    return 0;
}