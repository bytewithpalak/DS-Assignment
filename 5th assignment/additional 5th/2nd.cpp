#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverseK(Node* head, int k) {
    Node *prev = NULL, *curr = head, *nxt = NULL;
    int count = 0;
    while (curr && count < k) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    if (nxt) head->next = reverseK(nxt, k);
    return prev;
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node{1, nullptr};
    Node* temp = head;
    for (int i = 2; i <= 8; i++) {
        temp->next = new Node{i, nullptr};
        temp = temp->next;
    }
    int k = 3;
    head = reverseK(head, k);
    print(head);
}
