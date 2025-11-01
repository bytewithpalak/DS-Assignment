#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

Node* head = NULL;

void insertEnd(int x) {
    Node* n = new Node();
    n->data = x;
    n->next = NULL;
    if (!head) {
        n->prev = NULL;
        head = n;
        return;
    }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void insertBeg(int x) {
    Node* n = new Node();
    n->data = x;
    n->next = head;
    n->prev = NULL;
    if (head) head->prev = n;
    head = n;
}

void deleteNode(int x) {
    Node* t = head;
    while (t && t->data != x) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    else head = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
}

void searchNode(int x) {
    Node* t = head;
    while (t) {
        if (t->data == x) {
            cout << "Found\n";
            return;
        }
        t = t->next;
    }
    cout << "Not Found\n";
}

void display() {
    Node* t = head;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << "\n";
}

int main() {
    int ch, x;
    do {
        cout << "1.InsertBeg 2.InsertEnd 3.Delete 4.Search 5.Display 0.Exit\n";
        cin >> ch;
        if (ch == 1) {cin >> x; insertBeg(x);}
        else if (ch == 2) {cin >> x; insertEnd(x);}
        else if (ch == 3) {cin >> x; deleteNode(x);}
        else if (ch == 4) {cin >> x; searchNode(x);}
        else if (ch == 5) display();
    } while (ch != 0);
}
