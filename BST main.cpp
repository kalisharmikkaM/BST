#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int ids[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(ids) / sizeof(ids[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, ids[i]);

    cout << "Employee IDs in ascending order: ";
    inorder(root);

    cout << endl;
    return 0;
}
