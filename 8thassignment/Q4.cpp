#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) { val = v; left = right = NULL; }
};

class CheckBST {
public:
    bool validate(Node* root, long long minVal, long long maxVal) {
        if (root == NULL) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return validate(root->left, minVal, root->val) &&
               validate(root->right, root->val, maxVal);
    }

    bool isBST(Node* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);

    CheckBST cb;

    cout << (cb.isBST(root) ? "BST" : "Not BST");

    return 0;
}
