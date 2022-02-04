#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

vector<vector<int>> levelOrder(Node* node)
{
    vector<vector<int>> res;
    vector<int> rs;
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        int count = q.size();
        for (int i=0; i<count; ++i) {
            Node* temp = q.front();
            q.pop();
            rs.push_back(temp->data);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        res.push_back(rs);
        rs.clear();
    }
    return res;
}


int main() {
    Node* head = new Node(10);
    head->left = new Node(3);
    head->right = new Node(14);
    return 0;
}