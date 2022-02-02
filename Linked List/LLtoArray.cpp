#include <bits/stdc++.h>
using namespace std;

struct LinkedList {
    int value;
    LinkedList* next;
    LinkedList(int data) : value(data), next(NULL) {}
};



int main() {
    LinkedList* head = new LinkedList(1);
    head->next = new LinkedList(2);
    head->next->next = new LinkedList(3);
    head->next->next->next = new LinkedList(3);
    head->next->next->next->next = new LinkedList(2);
    return 0;
}