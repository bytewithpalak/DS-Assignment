#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int searchInorder(int inorder[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTreePreIn(int preorder[], int inorder[],
                     int inStart, int inEnd,
                     int &preIndex, int n) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = preorder[preIndex++];
    Node *root = new Node(rootVal);

    if (inStart == inEnd)
        return root;

    int inIndex = searchInorder(inorder, n, rootVal);

    root->left = buildTreePreIn(preorder, inorder, inStart, inIndex - 1, preIndex, n);
    root->right = buildTreePreIn(preorder, inorder, inIndex + 1, inEnd, preIndex, n);

    return root;
}

void printInorder(Node *root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int preorder[100], inorder[100];

    cout << "Enter preorder: ";
    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    cout << "Enter inorder: ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    int preIndex = 0;
    Node *root = buildTreePreIn(preorder, inorder, 0, n - 1, preIndex, n);

    cout << "Inorder of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
