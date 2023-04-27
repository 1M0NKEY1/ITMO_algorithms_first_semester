#include <iostream>

using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;
};

bool search(Node* root, string key) {
    if (root == nullptr) {
        return false;
    }
    if (root->value == key) {
        return true;
    }
    if (key < root->value) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

Node* insert(Node* root, string key) {
    if (root == nullptr) {
        root = new Node;
        root->value = key;
        root->left = nullptr;
        root->right = nullptr;
    } else if (root->value == key) {
        return root;
    } else if (key < root->value) {
        root->left = insert(root->left, key);
    } else if (key > root->value) {
        root->right = insert(root->right, key);
    }
    return root;
}

int main() {

    Node* tree1 = nullptr;
    Node* tree2 = nullptr;
    Node* tree3 = nullptr;

    int n;
    cin >> n;

    int first_boy = 0;
    int second_boy = 0;
    int third_boy = 0;

    string first[n];
    string second[n];
    string third[n];

    for (int i = 0; i < n; i++) {
        cin >> first[i];
        tree1 = insert(tree1, first[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> second[i];
        tree2 = insert(tree2, second[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> third[i];
        tree3 = insert(tree3, third[i]);
    }

    for (int i = 0; i < n; i++) {
        if (!search(tree2, first[i]) && !search(tree3, first[i])) {
            first_boy += 3;
        }
        if (!search(tree2, first[i]) && search(tree3, first[i])){
            first_boy += 1;
        } else if (search(tree2, first[i]) && !search(tree3, first[i])) {
            first_boy += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!search(tree1, second[i]) && !search(tree3, second[i])) {
            second_boy += 3;
        }
        if (!search(tree1, second[i]) && search(tree3, second[i])){
            second_boy += 1;
        } else if (search(tree1, second[i]) && !search(tree3, second[i])) {
            second_boy += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!search(tree1, third[i]) && !search(tree2,third[i])) {
            third_boy += 3;
        }
        if (!search(tree1, third[i]) && search(tree2, third[i])){
            third_boy += 1;
        } else if (search(tree1, third[i]) && !search(tree2, third[i])) {
            third_boy += 1;
        }
    }

    cout << first_boy << ' ';
    cout << second_boy << ' ';
    cout << third_boy << ' ';

    return 0;
}
