#include <bits/stdc++.h>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
};

Node* addPoly(Node* p1, Node* p2) {
    Node* res = NULL, *tail = NULL;
    while (p1 && p2) {
        Node* temp = new Node();
        if (p1->pow == p2->pow) {
            temp->coeff = p1->coeff + p2->coeff;
            temp->pow = p1->pow;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            temp->coeff = p1->coeff;
            temp->pow = p1->pow;
            p1 = p1->next;
        } else {
            temp->coeff = p2->coeff;
            temp->pow = p2->pow;
            p2 = p2->next;
        }
        temp->next = NULL;
        if (!res) res = tail = temp;
        else { tail->next = temp; tail = temp; }
    }
    while (p1) {
        Node* temp = new Node{p1->coeff, p1->pow, NULL};
        tail->next = temp;
        tail = temp;
        p1 = p1->next;
    }
    while (p2) {
        Node* temp = new Node{p2->coeff, p2->pow, NULL};
        tail->next = temp;
        tail = temp;
        p2 = p2->next;
    }
    return res;
}

void print(Node* head) {
    while (head) {
        cout << "[" << head->coeff << "," << head->pow << "] ";
        head = head->next;
    }
}


int main() {
    Node* p1 = new Node{5,2,new Node{4,1,new Node{2,0,NULL}}};
    Node* p2 = new Node{5,1,new Node{5,0,NULL}};
    Node* res = addPoly(p1,p2);
    print(res);
}
