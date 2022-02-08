#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right, *parent;
    Node(int data, Node* parent) : data(data), left(NULL), right(NULL), parent(parent) {}
 };
//     case 1:
//             if its right child is present then we go to the leftmost child of the right child
//     case 2:
//             if it is the left child of the parent then simply parent is the successor
//     case 3: 
//             if it is the right child of the parent then we go upward until the node is the left child of the parent
//             and then the right child of the parent is the successor

int successor(Node* node) {
    if (!node->parent && !node->right) return -1;
    if (node->right) {
        node = node->right;
        while (node->left) {
            node = node->left;
        }
        return node->data;
    } else if (node == node->parent->left) {
        return node->parent->data;
    } else {
        Node* parent = node->parent;
        while (parent && node == parent->right) {
            node = parent;
            parent = parent->parent;
        }
        if (!node) return -1;
        return parent->data;
    }
}


int main() {
    Node* head = new Node(10, NULL);
    head->left = new Node(15, head);
    head->right = new Node(8, head);
    head->left->left = new Node(3, head->left);
    head->left->right = new Node(4, head->left);
    head->left->right->left = new Node(2, head->left->right);
    head->left->right->right = new Node(20, head->left->right);

    head->right->right = new Node(6, head->right);
    head->right->right->left = new Node(2, head->right->right);
    head->right->right->right = new Node(1, head->right->right);
    
    cout << successor(head->left->right);
    return 0;
}