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

Node* buildTreeInPost(int inorder[], int postorder[],
                      int inStart, int inEnd,
                      int &postIndex, int n) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[postIndex--];
    Node *root = new Node(rootVal);

    if (inStart == inEnd)
        return root;

    int inIndex = searchInorder(inorder, n, rootVal);
    root->right = buildTreeInPost(inorder, postorder, inIndex + 1, inEnd, postIndex, n);
    root->left  = buildTreeInPost(inorder, postorder, inStart, inIndex - 1, postIndex, n);

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

    int inorder[100], postorder[100];

    cout << "Enter inorder: ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    cout << "Enter postorder: ";
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    int postIndex = n - 1;
    Node *root = buildTreeInPost(inorder, postorder, 0, n - 1, postIndex, n);

    cout << "Inorder of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
