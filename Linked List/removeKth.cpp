

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int data) : value(data), next(NULL) {}
};

ListNode* removekthElement (ListNode* head, int k) {
    if (k == 1) {
		head = head->next;
		return head;
	}
	k -= 1;
	ListNode* temp = head;
	while (--k && temp != NULL) {
		temp = temp->next;
	}
	temp->next = temp->next->next;
	return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    return 0;
}