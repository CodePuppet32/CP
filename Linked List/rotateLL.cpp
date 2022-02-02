#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data) : data(data), next(NULL) {}
};

ListNode* rotateListByK(ListNode* head, int k) {
	if (!head)
		return NULL;
	int size = 1;
	ListNode* ahead = head;
	
	while (ahead->next) {
		++size;
		ahead = ahead->next;
	}
	k %= size;
	
	if (k) {
		ahead->next = head;
	} else {
		return head;
	}
	
	ahead = head;
	k = size-k;
	while (--k)
		ahead = ahead->next;
	ListNode* res = ahead->next;
	ahead->next = NULL;
	return res;
	
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    return 0;
}