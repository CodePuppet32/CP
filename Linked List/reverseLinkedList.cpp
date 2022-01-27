#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
    node() : data(0), next(NULL), prev(NULL) {}
    node(int data) : data(data), next(NULL), prev(NULL) {}
    node(int data, node* next) : data(data), next(next), prev(NULL) {}
    node(int data, node* next, node* prev) : data(data), next(next), prev(prev) {}
};

void printDLL(node* head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        cout << "NL<-" << head->data << "->NL";
        return;
    }
    else
        cout << "NL<-" << head->data << "->" << head->next->data << '\n';
    head = head->next;

    while (head->next != NULL) {
        cout << head->prev->data << "<-" << head->data << "->" << head->next->data << '\n';
        head = head->next;
    }
    cout << head->prev->data << "<-" << head->data << "->" << "NL";
}

node* reverseDLL(node* head) {
    if (head == NULL || head->next == NULL) return head;
    
    do {
        node* prev = head->prev;
        head->prev = head->next;
        head->next = prev;
        if (head->prev == NULL)
            break;
        head = head->prev;
    }while (1);

    return head;
}

int main() {
    node* head = new node(10);
    head->next = new node(20, NULL, head);
    head->next->next = new node(30, NULL, head->next);
    head->next->next->next = new node(40, NULL, head->next->next);
    head = reverseDLL(head);
    printDLL(head);
    return 0;
}