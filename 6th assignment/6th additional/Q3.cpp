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

    void push_back(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n; n->prev = cur;
    }

    Node* reverseGroup(Node* start, int k, Node*& newTail, Node*& nextGroupHead) {
        Node* cur = start;
        Node* prev = nullptr;
        int cnt = 0;
        while (cur && cnt < k) {
            Node* nxt = cur->next;
            cur->next = prev;
            cur->prev = nxt;
            prev = cur;
            cur = nxt;
            cnt++;
        }
        newTail = start;
        nextGroupHead = cur;
        return prev;
    }

    void reverseInGroups(int k) {
        if (!head || k <= 1) return;
        Node *overallHead = nullptr, *prevTail = nullptr, *cur = head;
        while (cur) {
            Node *newTail, *nextGroup, *newHead;
            newHead = reverseGroup(cur, k, newTail, nextGroup);
            if (!overallHead) overallHead = newHead;
            if (prevTail) {
                prevTail->next = newHead;
                newHead->prev = prevTail;
            }
            newTail->next = nextGroup;
            if (nextGroup) nextGroup->prev = newTail;
            prevTail = newTail;
            cur = nextGroup;
        }
        head = overallHead;
    }

    void print() {
        Node* cur = head;
        while (cur) { cout << cur->data << " "; cur = cur->next; }
        cout << "\n";
    }
};

int main() {
    DList dl;
    for (int i=1;i<=6;i++) dl.push_back(i);
    dl.reverseInGroups(2);
    dl.print();

    DList dl2;
    for (int i=1;i<=6;i++) dl2.push_back(i);
    dl2.reverseInGroups(4);
    dl2.print();
}
