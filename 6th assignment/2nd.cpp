#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void print(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data;
}
int main() {
    Node* a = new Node{20,NULL};
    Node* b = new Node{100,NULL};
    Node* c = new Node{40,NULL};
    Node* d = new Node{80,NULL};
    Node* e = new Node{60,NULL};
    a->next=b; b->next=c; c->next=d; d->next=e; e->next=a;
    print(a);
}
