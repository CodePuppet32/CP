#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

void diagonalTraversal(Node* head) {
    queue<Node*> q;
    q.push(head);
    Node* temp = head;
    while (temp->right) {
        q.push(temp->right);
        temp = temp->right;
    }
    while (!q.empty()) {
        int count = q.size();
        for (int i = 0; i < count; ++i) {
            // get a node from the queue
            Node* temp = q.front();
            // print its data
            cout << temp->data << " ";
            // pop it
            q.pop();
            if (temp->left) {
                // assign it to its left and push it
                temp = temp->left;
                q.push(temp);
                // while it has right child keep adding it
                while (temp->right) {
                    temp = temp->right;
                    q.push(temp);
                }
            }
            
        }
        cout << endl;
    }
}


int main() {
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);

    head->right->left = new Node(5);
    head->right->left->left = new Node(7);
    head->right->left->right = new Node(8);
    head->right->right = new Node(6);
    diagonalTraversal(head);
    return 0;
}