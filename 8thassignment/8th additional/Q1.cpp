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

bool isLeaf(Node *node) {
    if (node == NULL) return false;
    return (node->left == NULL && node->right == NULL);
}

int sumLeftLeaves(Node *root) {
    if (root == NULL) return 0;

    int sum = 0;

    if (isLeaf(root->left))
        sum += root->left->data;

    sum += sumLeftLeaves(root->left);
    sum += sumLeftLeaves(root->right);

    return sum;
}

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

    cout << "Sum of Left Leaves = " << sumLeftLeaves(root);

    return 0;
}
