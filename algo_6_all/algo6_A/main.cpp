#include <iostream>

using namespace std;

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
    Node(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int height(Node* p) {
    if (p != nullptr) {
        return p->height;
    } else {
        return 0;
    }
}

int balance(Node* p) {
    return height(p->right) - height(p->left);
}

void fixed_height(Node* p) {
    unsigned char left_height = height(p->left);
    unsigned char right_height = height(p->right);
    p->height = (left_height > right_height?left_height:right_height) + 1;
}

int main() {
    int n;
    cin >> n;

    Node* node;

    int key_val;
    int left_val;
    int right_val;

    for (int i = 0; i < n; i++) {
        cin >> key_val >> left_val >> right_val;
        node->key = key_val;
        if (left_val != 0) {
            node->left->key = left_val;
        } else {
            node->left = nullptr;
        }
        if (right_val != 0) {
            node->right->key = right_val;
        } else {
            node->right = nullptr;
        }
        fixed_height(node);
        cout << height(node->left) - height(node->right) << "\n";
    }

    return 0;
}
