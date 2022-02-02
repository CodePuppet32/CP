#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data) : data(data), next(NULL) {}
};

ListNode* mergeTwoSortedList (ListNode* firstList, ListNode* secondList) {
    ListNode* res = firstList->data<secondList->data? firstList: secondList;
	firstList->data<secondList->data? firstList=firstList->next: secondList=secondList->next;
	ListNode* retun = res;
	
	while (firstList && secondList) {
		if (firstList->data < secondList->data) {
			res->next = firstList;
			firstList = firstList->next;
		} else {
			res->next = secondList;
			secondList = secondList->next;
		}
		res = res->next;
	}
	
	if (firstList) {
		res->next = firstList;
	} else {
		res->next = secondList;
	}
	
	return retun;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    return 0;
}