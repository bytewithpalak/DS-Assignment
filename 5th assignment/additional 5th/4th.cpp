#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* rotate(Node* head, int k) {
    if (!head || k == 0) return head;
    Node* temp = head;
    int len = 1;
    while (temp->next) {
        temp = temp->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    temp->next = head;
    Node* curr = head;
    for (int i = 1; i < len - k; i++) curr = curr->next;
    head = curr->next;
    curr->next = NULL;
    return head;
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node{10, new Node{20, new Node{30, new Node{40, new Node{50, NULL}}}}};
    int k = 4;
    head = rotate(head, k);
    print(head);
}
