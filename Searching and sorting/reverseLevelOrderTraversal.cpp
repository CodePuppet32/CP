#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

void printReverseLevelOrder(Node* head) {
    stack<int> stk;
    queue<Node*> q;
    q.push(head);
    while (!q.empty()) {
        int count = q.size();
        for (int i = 0; i < count; ++i) {
            Node* temp = q.front();
            q.pop();
            stk.push(temp->data);
            if (temp->right) q.push(temp->right);
            if (temp->left) q.push(temp->left);
        }
    }
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
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
    
    printReverseLevelOrder(head);
    return 0;
}