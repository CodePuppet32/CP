#include <bits/stdc++.h>
using namespace std;

void printStack(vector<int> &stack) {
	for (int i = 0; i < stack.size(); i++) {
		cout << stack[i] << " ";
	}
	cout << endl;
}

void helperFunc(vector<int> &stack) {
	if (stack.size() == 1) return;
	int top_element = stack[stack.size()-1];
	stack.pop_back();
	int second_element = stack[stack.size()-1];
	stack.pop_back();

	if (top_element < second_element) {
		stack.push_back(top_element);
		top_element = second_element;
	} else {
		stack.push_back(second_element);
	}
	helperFunc(stack);
    stack.push_back(top_element);
}

vector<int> sortStack(vector<int> &stack) {
	for (int i=0; i<stack.size(); ++i) {
		helperFunc(stack);
	}
	return stack;
}

int main() {
    vector<int> stack {-5, 2, -2, 4, 3, 1};
    sortStack(stack);
	printStack(stack);
    return 0;
}