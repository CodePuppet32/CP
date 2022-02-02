#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data) : data(data), next(NULL) {}
};

ListNode* xthNodeFromEnd(ListNode* head, int x) {
	ListNode* ahead = head;
	ListNode* behind = head;
	
	while (x--)
		ahead = ahead->next;

	while (ahead != NULL) {
		ahead = ahead->next;
		behind = behind->next;
	}
	return behind;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    return 0;
}