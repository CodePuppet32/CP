#include <bits/stdc++.h>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST &insert(int val) {
		BST *head = this;
		while (1) {
			if (head->value > val && head->left == NULL) {
				head->left = new BST(val);
				break;
			} else if (head->value <= val && head->right == NULL) {
				head->right = new BST(val);
				break;
			} else if (head->value > val) {
				head = head->left;
			} else {
				head = head->right;
			}
		}
    return *this;
  }

  bool contains(int val) {
		BST *head = this;
		while(head != NULL) {
			if (head->value == val)
				return true;
			else if (head->value > val)
				head = head->left;
			else
				head = head->right;
		}
		return false;
  }

  BST &remove(int val) {
	BST *head = this;
    if (this->right == NULL && this->left == NULL) {
		return *this;
	}
    BST* pre = NULL;
    while (head != NULL) {
        if (head->value == val) {
            break;
        } else if (head->value > val) {
            head = head->left;
        } else {
            head = head->right;
        }
    }
    if (head != NULL) {
        BST* temp = head;
        BST* pre = NULL;
        if (head->right != NULL) {
            pre = temp;
            temp = temp->right;
            if (temp->left == NULL) {
                head->value = temp->value;
                head->right = temp->right;
                return *this;
            }
        }   
        while (temp->left != NULL) {
            pre = temp;
            temp = temp->left;
        }
        head->value = temp->value;
        pre->left = temp->right;
    }
    return *this;
  }
};

int BST_ceil(BST *head, int number) {
    int res = INT_MAX;

    while (head) {
        if (head->value >= number) {
            res = head->value;
            head = head->left;
        } else {
            head = head->right;
        }
    }
    return res;
}

int main() {
    BST* head = new BST(10);
    head->left = new BST(5);
    head->right = new BST(15);
    head->right->right = new BST(30);
    head->right->left = new BST(12);
    
    cout << BST_ceil(head, 100) << endl;
    return 0;

}