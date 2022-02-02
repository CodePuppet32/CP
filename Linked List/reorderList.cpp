#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data) : data(data), next(NULL) {}
};

ListNode* reverse(ListNode* head) {
	ListNode* pre=NULL;
	while (head) {
		ListNode* next = head->next;
	 	head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

ListNode* reorderList(ListNode* head) {
	int size = 0;
	ListNode* temp = head;
	while (temp) {
		++size;
		temp = temp->next;
	}
	if (size < 3)
		return head;
	
    size = size%2? (size/2)+1 : size/2;

	temp = head;
	
	while (--size) {
		temp = temp->next;
	}
	ListNode* secondNode = temp->next;
	temp->next = NULL;
	
	secondNode = reverse(secondNode);
	ListNode* res = head;
	ListNode* first = head->next;

    int count = 0;

	while (secondNode) {
		res->next=secondNode;
		secondNode=secondNode->next;
		res->next->next = first;
        if (first)
		    first=first->next;
		res = res->next->next;
        ++count;
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