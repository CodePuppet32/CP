#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){}
};

vector<int> levelOrder(Node* node)
    {
      vector<int> res;
      vector<Node*> queue;
      queue.push_back(node);
      while (!queue.empty()) {
          Node* temp = queue[0];
          res.push_back(temp->data);
          if (temp->left)
            queue.push_back(temp->left);
          if (temp->right)
            queue.push_back(temp->right);
          queue.erase(queue.begin());        
      }
      return res;
    }


int main() {
    Node* head = new Node(10);
    head->left = new Node(3);
    head->right = new Node(14);
    return 0;
}