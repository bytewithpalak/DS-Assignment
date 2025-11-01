#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void removeLoop(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (slow != fast) return;
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int main() {
    Node* head = new Node{1, nullptr};
    Node* temp = head;
    for (int i = 2; i <= 6; i++) {
        temp->next = new Node{i, nullptr};
        temp = temp->next;
    }
    temp->next = head->next->next;
    removeLoop(head);
    temp = head;
    for (int i = 0; i < 6; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
