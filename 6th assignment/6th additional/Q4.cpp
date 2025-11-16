#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node(int d): data(d), next(nullptr), prev(nullptr) {}
};

class DList {
public:
    Node* head;
    DList(): head(nullptr) {}

    void append(Node* n) {
        if (!head) { head = n; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
        n->prev = cur;
    }

    void correctPointer() {
        if (!head) return;
        if (head->next && head->next->prev != head) {
            head->next->prev = head;
            return;
        }
        if (head->prev) {
            head->prev = nullptr;
            return;
        }
        Node* temp = head->next;
        while (temp) {
            if (temp->next && temp->next->prev != temp) {
                temp->next->prev = temp;
                return;
            }
            if (temp->prev && temp->prev->next != temp) {
                temp->prev->next = temp;
                return;
            }
            temp = temp->next;
        }
    }
};

int main() {
    DList dl;
    dl.head = new Node(1);
    dl.head->next = new Node(2);
    dl.head->next->next = new Node(3);
    dl.head->next->next->prev = dl.head;
    dl.correctPointer();
}
