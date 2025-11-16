#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

class BST {
public:
    Node* insert(Node* root, int key) {
        if (root == NULL) return new Node(key);
        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        return root;
    }
    Node* searchRec(Node* root, int key) {
        if (root == NULL || root->key == key) return root;
        if (key < root->key) return searchRec(root->left, key);
        return searchRec(root->right, key);
    }
    Node* searchItr(Node* root, int key) {
        while (root != NULL) {
            if (root->key == key) return root;
            if (key < root->key) root = root->left;
            else root = root->right;
        }
        return NULL;
    }

    Node* findMin(Node* root) {
        while (root->left != NULL) root = root->left;
        return root;
    }

    Node* findMax(Node* root) {
        while (root->right != NULL) root = root->right;
        return root;
    }
    Node* successor(Node* root, int key) {
        Node* curr = searchItr(root, key);
        if (curr == NULL) return NULL;

        if (curr->right) return findMin(curr->right);

        Node* succ = NULL;
        Node* ancestor = root;
        while (ancestor != curr) {
            if (key < ancestor->key) {
                succ = ancestor;
                ancestor = ancestor->left;
            } else ancestor = ancestor->right;
        }
        return succ;
    }
    Node* predecessor(Node* root, int key) {
        Node* curr = searchItr(root, key);
        if (curr == NULL) return NULL;

        if (curr->left) return findMax(curr->left);

        Node* pred = NULL;
        Node* ancestor = root;
        while (ancestor != curr) {
            if (key > ancestor->key) {
                pred = ancestor;
                ancestor = ancestor->right;
            } else ancestor = ancestor->left;
        }
        return pred;
    }
};

int main() {
    BST bst;
    Node* root = NULL;

    int arr[] = {20, 10, 5, 15, 30, 25, 35};
    for (int x : arr) root = bst.insert(root, x);

    cout << "Min: " << bst.findMin(root)->key << endl;
    cout << "Max: " << bst.findMax(root)->key << endl;

    Node* s = bst.successor(root, 15);
    if (s) cout << "Successor of 15: " << s->key << endl;

    Node* p = bst.predecessor(root, 25);
    if (p) cout << "Predecessor of 25: " << p->key << endl;

    return 0;
}
