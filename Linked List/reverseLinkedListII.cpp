#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data) : data(data), next(NULL) {}
};

ListNode* reverseLinkedListRange(ListNode* head, int left, int right) {
		ListNode* ll = head, *rl = head, *prev=head;
        int l = left;
        while (--left) {
            prev = ll;
            ll = ll->next;
        }
        while (--right) {
            rl = rl->next;
        }
        ListNode* pre = rl->next;
        
        while (ll != rl) {
            ListNode* next = ll->next;
            ll->next = pre;
            pre = ll;
            ll = next;
        }
        ll->next=pre;
        if (l == 1) {
            return rl;
        }
        prev->next = rl;
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