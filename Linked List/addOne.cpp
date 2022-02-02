#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data) : data(data), next(NULL) {}
};

int addOne(ListNode* head) {
	if (head == NULL)
		return 1;
	int carry = addOne(head->next);
	int sum = head->data+carry;
	carry = sum/10;
	head->data = sum%10;
	return carry;
}

ListNode* addOneToList(ListNode* head) {
	int carry = addOne(head);
	if (carry) {
		ListNode* temp = new ListNode(carry);
		temp->next=head;
		head=temp;
	}
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