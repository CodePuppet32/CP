#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

bool isIdentical(Node *r1, Node *r2)
    {
        if (!r1 && !r2) return true;
        if ((!r1 && r2) || (!r2 && r1)) return false;
        if (r1->data != r2->data) return false;
        return (isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));
    }

int main() {
    Node* head = new Node(10);
    head->left = new Node(3);
    head->right = new Node(14);
    return 0;
}