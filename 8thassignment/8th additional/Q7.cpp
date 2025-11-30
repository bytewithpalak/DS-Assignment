#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;  
    Node *right;  

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insertBST(Node *root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insertBST(root->left, key);
    else if (key > root->data)
        root->right = insertBST(root->right, key);
 
    return root;
}

void bstToDll(Node *root, Node* &head, Node* &prev) {
    if (root == NULL) return;

    bstToDll(root->left, head, prev);

    if (prev == NULL) {
        head = root;         
    } else {
        prev->right = root;  
        root->left = prev;
    }
    prev = root;

    bstToDll(root->right, head, prev);
}

Node* mergeDll(Node *h1, Node *h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    Node *head = NULL;
    Node *tail = NULL;
    if (h1->data < h2->data) {
        head = tail = h1;
        h1 = h1->right;
    } else {
        head = tail = h2;
        h2 = h2->right;
    }

    tail->left = NULL;  

    while (h1 != NULL && h2 != NULL) {
        if (h1->data < h2->data) {
            tail->right = h1;
            h1->left = tail;
            tail = h1;
            h1 = h1->right;
        } else {
            tail->right = h2;
            h2->left = tail;
            tail = h2;
            h2 = h2->right;
        }
    }
    while (h1 != NULL) {
        tail->right = h1;
        h1->left = tail;
        tail = h1;
        h1 = h1->right;
    }

    while (h2 != NULL) {
        tail->right = h2;
        h2->left = tail;
        tail = h2;
        h2 = h2->right;
    }

    return head;
}

void printDll(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data;
        if (curr->right != NULL) cout << " <-> ";
        curr = curr->right;
    }
    cout << endl;
}

int main() {
    int n1, n2, x;

    Node *root1 = NULL;
    Node *root2 = NULL;

    cout << "Enter number of nodes in BST1: ";
    cin >> n1;
    cout << "Enter elements of BST1: ";
    for (int i = 0; i < n1; i++) {
        cin >> x;
        root1 = insertBST(root1, x);
    }

    cout << "Enter number of nodes in BST2: ";
    cin >> n2;
    cout << "Enter elements of BST2: ";
    for (int i = 0; i < n2; i++) {
        cin >> x;
        root2 = insertBST(root2, x);
    }

    Node *head1 = NULL, *prev1 = NULL;
    Node *head2 = NULL, *prev2 = NULL;

    bstToDll(root1, head1, prev1);
    bstToDll(root2, head2, prev2);

    Node *mergedHead = mergeDll(head1, head2);

    cout << "Merged Doubly Linked List: ";
    printDll(mergedHead);

    return 0;
}
