#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

int findMaxValue(Node* root) {
    // tree kosong
    if (root == nullptr) {
        return -1;
    }
    
    // terus ke kanan sampe mentok
    while (root->right != nullptr) {
        root = root->right;
    }
    
    return root->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);
    
    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl;
    
    return 0;
}