#include <bits/stdc++.h>
using namespace std;

struct LinkedList {
    int value;
    LinkedList* next;
    LinkedList(int data) : value(data), next(NULL) {}
};

void print(LinkedList* head) {
    while (head) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

LinkedList* reverse(LinkedList* head) {
	LinkedList* pre = NULL;
	while (head) {
		LinkedList* next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

bool linkedListPalindrome(LinkedList *head) {
	LinkedList *slow=head, *fast = head;
	
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	slow = reverse(slow);
	fast = head;
	while (fast && slow) {
		if (fast->value != slow->value)
			return false;
		fast = fast->next;
		slow = slow->next;
	}
  return true;
}

int main() {
    LinkedList* head = new LinkedList(1);
    head->next = new LinkedList(2);
    head->next->next = new LinkedList(3);
    head->next->next->next = new LinkedList(3);
    head->next->next->next->next = new LinkedList(2);
    head->next->next->next->next->next = new LinkedList(1);
    //head->next->next->next->next->next->next = new LinkedList(1);
    cout << linkedListPalindrome(head);
    print(head);
    return 0;
}