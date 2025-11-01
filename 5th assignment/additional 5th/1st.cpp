#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int length(Node* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

int getIntersection(Node* h1, Node* h2) {
    int n1 = length(h1);
    int n2 = length(h2);
    int d = abs(n1 - n2);

    if (n1 > n2) {
        while (d--) h1 = h1->next;
    } else {
        while (d--) h2 = h2->next;
    }

    while (h1 && h2) {
        if (h1 == h2) return h1->data;
        h1 = h1->next;
        h2 = h2->next;
    }
    return -1;
}

int main() {
    Node* head1 = new Node{4, nullptr};
    head1->next = new Node{1, nullptr};
    Node* head2 = new Node{5, nullptr};
    head2->next = new Node{6, nullptr};
    head2->next->next = new Node{1, nullptr};

    Node* common = new Node{8, new Node{4, new Node{5, nullptr}}};
    head1->next->next = common;
    head2->next->next->next = common;

    cout << "Intersected at " << getIntersection(head1, head2);
}
