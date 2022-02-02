#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data) : data(data), next(NULL) {}
};

ListNode* getStartingNodeOfLoop(ListNode* list){
	ListNode* fast = list;
	ListNode* slow = list;
	
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	if (!fast || !fast->next)
		return NULL;

	slow = list;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    return 0;
}