#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};


Node* LCA(Node* head, int first, int second) {
    if (!head) return NULL;
    if (head->data == first || head->data == second) return head;
    Node* lca1 = LCA(head->left, first, second);
    Node* lca2 = LCA(head->right, first, second);
    if (lca1 && lca2) return head;
    if (lca1) return lca1;
    else return lca2;
}


int main() {
    Node* head = new Node(10);
    head->left = new Node(15);
    head->right = new Node(8);
    head->left->left = new Node(3);
    head->left->right = new Node(4);
    head->left->right->left = new Node(5);
    head->left->right->right = new Node(20);

    head->right->right = new Node(6);
    head->right->right->left = new Node(2);
    head->right->right->right = new Node(1);
    Node* lca = LCA(head, 3, 20);
    cout << lca->data << endl;
    return 0;
}