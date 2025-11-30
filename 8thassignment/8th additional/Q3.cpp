#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int main() {
    int x;
    cout << "Enter root: ";
    cin >> x;

    if (x == -1) return 0;

    Node *root = new Node(x);

    Node* q[100];
    int front = 0, rear = 0;
    q[rear++] = root;

    while (front < rear) {
        Node *temp = q[front++];

        cout << "Enter left of " << temp->data << ": ";
        cin >> x;
        if (x != -1) {
            temp->left = new Node(x);
            q[rear++] = temp->left;
        }

        cout << "Enter right of " << temp->data << ": ";
        cin >> x;
        if (x != -1) {
            temp->right = new Node(x);
            q[rear++] = temp->right;
        }
    }

    cout << "Right View: ";

    front = 0;
    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            Node *temp = q[front++];

            if (i == levelSize - 1)
                cout << temp->data << " ";

            if (temp->left) q[rear++] = temp->left;
            if (temp->right) q[rear++] = temp->right;
        }
    }

    return 0;
}
