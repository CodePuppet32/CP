#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

int height(struct Node* node){
        if (!node) return 0;
        return (1 + max(height(node->left), height(node->right)));
    }

int main() {
    Node* head = new Node(10);
    head->left = new Node(3);
    head->right = new Node(14);
    return 0;
}