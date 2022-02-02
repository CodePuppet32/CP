

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int data) : value(data), next(NULL) {}
};

ListNode* appendLists (ListNode* list1, ListNode* list2) {
    // add your logic here
	if (!list1)
		return list2;
	ListNode* temp = list1;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = list2;
	return list1;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    return 0;
}