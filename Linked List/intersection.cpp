#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data) : data(data), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode *A, ListNode *B) {
    int len1=0, len2=0;
	
	ListNode* t1=A, *t2=B;
	
	while (t1) {
		++len1;
		t1 = t1->next;
	}
	while (t2) {
		++len2;
		t2 = t2->next;
	}
	
	t1 = A;
	t2 = B;
	
	if (len1 > len2) {
		int len_diff = len1-len2;
		while(len_diff--)
			t1 = t1->next;
	} else {
		int len_diff = len2-len1;
		while(len_diff--)
			t2 = t2->next;
	}
	
	while (t1 && t2 && t1 != t2) {
		t1 = t1->next;
		t2 = t2->next;
	}
	return t1 == t2? t1: NULL;
	
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    return 0;
}