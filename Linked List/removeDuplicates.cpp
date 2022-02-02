#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data) : data(data), next(NULL) {}
};

ListNode* removeDuplicates(ListNode* head) {
	if (!head || head->next == NULL)
		return head;
	
	ListNode* ahead = head->next;
	ListNode* behind = head;
	
	while (ahead != NULL) {
		if (ahead->data == behind->data) {
			behind->next = behind->next->next;
		} else
			behind = behind->next;
	
		ahead = ahead->next;
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