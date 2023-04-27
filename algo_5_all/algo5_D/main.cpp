#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* next(Node* root, int key) {
    Node* current = root;
    Node* successor = nullptr;
    while (current != nullptr) {
        if (current->key > key) {
            successor = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return successor;
}

Node* previous(Node* root, int key) {
    Node* current = root;
    Node* successor = nullptr;
    while (current != nullptr) {
        if (current->key < key) {
            successor = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return successor;
}

Node* minimum(Node* root) {
    if (root->left == nullptr) {
        return root;
    }
    return minimum(root->left);
}

bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->key == key) {
        return true;
    }
    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        root = new Node;
        root->key = key;
        root->left = nullptr;
        root->right = nullptr;
    } else if (root->key == key) {
        return root;
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* del(Node* root, int deleted_key) {
    if (root == nullptr) {
        return root;
    }
    if (deleted_key < root->key) {
        root->left = del(root->left, deleted_key);
    } else if (deleted_key > root->key) {
        root->right = del(root->right, deleted_key);
    } else if (root->left != nullptr && root->right != nullptr) {
        root->key = minimum(root->right)->key;
        root->right = del(root->right, root->key);
    } else {
        if (root->left != nullptr) {
            root = root->left;
        } else if (root->right != nullptr) {
            root = root->right;
        } else {
            root = nullptr;
        }
    }
    return root;
}

int main() {

    Node* root = nullptr;
    int key;
    string S;

    while (cin >> S) {
        cin >> key;
        if (S == "insert") {
            root = insert(root, key);
        } else if (S == "delete") {
            root = del(root, key);
        } else if (S == "exists") {
            if (!search(root, key)) {
                cout << "false\n";
            } else {
                cout << "true\n";
            }
        } else if (S == "next") {
            Node* tmp_next = next(root, key);
            if (tmp_next != nullptr) {
                cout << tmp_next->key << "\n";
            } else {
                cout << "none\n";
            }
        } else if (S == "prev") {
            Node* tmp_previous = previous(root, key);
            if (tmp_previous != nullptr) {
                cout << tmp_previous->key << "\n";
            } else {
                cout << "none\n";
            }
        }
    }
    return 0;
}
