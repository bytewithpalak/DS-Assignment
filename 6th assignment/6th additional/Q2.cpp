#include <bits/stdc++.h>
using namespace std;

class CNode {
public:
    int data;
    CNode* next;
    CNode(int d): data(d), next(nullptr) {}
};

class Circular {
public:
    CNode* head;
    Circular(): head(nullptr) {}

    void push_back(int x) {
        CNode* n = new CNode(x);
        if (!head) { head = n; n->next = head; return; }
        CNode* cur = head;
        while (cur->next != head) cur = cur->next;
        cur->next = n;
        n->next = head;
    }

    void removeEvenParity() {
        if (!head) return;
        while (head && (__builtin_popcount(head->data) % 2 == 0)) {
            if (head->next == head) { delete head; head = nullptr; return; }
            CNode* last = head;
            while (last->next != head) last = last->next;
            CNode* t = head;
            head = head->next;
            last->next = head;
            delete t;
        }
        if (!head) return;
        CNode* cur = head;
        while (cur->next != head) {
            if (__builtin_popcount(cur->next->data) % 2 == 0) {
                CNode* t = cur->next;
                cur->next = t->next;
                delete t;
            } else cur = cur->next;
        }
    }

    void print() {
        if (!head) { cout << "Empty\n"; return; }
        CNode* cur = head;
        do { cout << cur->data << " "; cur = cur->next; } while (cur != head);
        cout << "\n";
    }
};

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d): data(d), prev(nullptr), next(nullptr) {}
};

class Doubly {
public:
    DNode* head;
    Doubly(): head(nullptr) {}

    void push_back(int x) {
        DNode* n = new DNode(x);
        if (!head) { head = n; return; }
        DNode* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
        n->prev = cur;
    }

    void removeEvenParity() {
        DNode* cur = head;
        while (cur) {
            DNode* nxt = cur->next;
            if (__builtin_popcount(cur->data) % 2 == 0) {
                if (cur->prev) cur->prev->next = cur->next;
                else head = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                delete cur;
            }
            cur = nxt;
        }
    }

    void print() {
        DNode* cur = head;
        while (cur) { cout << cur->data << " "; cur = cur->next; }
        cout << "\n";
    }
};

int main() {
    Circular c;
    for (int v : {9,11,34,6,13,21}) c.push_back(v);
    c.removeEvenParity();
    c.print();

    Doubly d;
    for (int v : {18,15,8,9,14}) d.push_back(v);
    d.removeEvenParity();
    d.print();
}
