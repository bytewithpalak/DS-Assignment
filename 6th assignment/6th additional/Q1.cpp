#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

class CircularList {
public:
    Node* head;
    CircularList(): head(nullptr) {}

    void push(int x) { 
        Node* node = new Node(x);
        if (!head) { head = node; node->next = head; return; }
        Node* cur = head;
        while (cur->next != head) cur = cur->next;
        cur->next = node;
        node->next = head;
    }

    pair<Node*,Node*> split() {
        if (!head) return {nullptr,nullptr};
        if (head->next == head) return {head, nullptr};

        Node *slow = head, *fast = head;
     
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
    
        if (fast->next->next == head) fast = fast->next;

        Node* head1 = head;
        Node* head2 = slow->next;

        fast->next = head2;   
        slow->next = head1;   

        return {head1, head2};
    }

    static void printCircular(Node* h) {
        if (!h) { cout << "Empty\n"; return; }
        Node* cur = h;
        do {
            cout << cur->data;
            cur = cur->next;
            if (cur != h) cout << " -> ";
        } while (cur != h);
        cout << "\n";
    }
};

int main() {
    CircularList cl;
    cl.push(10);
    cl.push(4);
    cl.push(9);
    auto halves = cl.split();
    cout << "First: "; CircularList::printCircular(halves.first);  
    cout << "Second: "; CircularList::printCircular(halves.second); 
    return 0;
}
