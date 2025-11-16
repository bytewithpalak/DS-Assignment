#include <iostream>
#include <algorithm>
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
        if (key < root->key) root->left = insert(root->left, key);
        else if (key > root->key) root->right = insert(root->right, key);
        return root;
    }

    Node* findMin(Node* root) {
        while (root->left != NULL) root = root->left;
        return root;
    }

    Node* Delete(Node* root, int key) {
        if (root == NULL) return root;

        if (key < root->key) root->left = Delete(root->left, key);
        else if (key > root->key) root->right = Delete(root->right, key);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = Delete(root->right, temp->key);
        }
        return root;
    }

    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int minDepth(Node* root) {
        if (root == NULL) return 0;
        if (root->left == NULL) return 1 + minDepth(root->right);
        if (root->right == NULL) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
};

int main() {
    BST bst;
    Node* root = NULL;

    int arr[] = {15, 10, 20, 8, 12, 17, 25};
    for (int x : arr) root = bst.insert(root, x);

    bst.inorder(root);
    cout << "\nMax Depth: " << bst.maxDepth(root);
    cout << "\nMin Depth: " << bst.minDepth(root);

    cout << "\nDeleting 10...";
    root = bst.Delete(root, 10);

    cout << "\nInorder after delete: ";
    bst.inorder(root);

    return 0;
}
