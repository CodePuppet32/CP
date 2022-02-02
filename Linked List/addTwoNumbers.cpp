#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data) : data(data), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* firstList, ListNode* secondList) {
	int sum = firstList->data + secondList->data;
	ListNode* res = new ListNode(sum%10);
	ListNode* result = res;
	int carry = sum/10;
	firstList = firstList->next;
	secondList = secondList->next;
	
	while (firstList || secondList || carry) {
		int num1 = firstList==NULL? 0: firstList->data;
		int num2 = secondList==NULL? 0: secondList->data;
		sum = num2+num1+carry;
		carry = sum/10;
		sum %= 10;
		
		res->next = new ListNode(sum);
		res = res->next;
		
		if (firstList != NULL) firstList = firstList->next;
		if (secondList != NULL) secondList = secondList->next;
	}
	return result;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    return 0;
}