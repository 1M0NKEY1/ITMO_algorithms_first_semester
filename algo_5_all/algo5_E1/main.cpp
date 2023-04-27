#include <iostream>

using namespace std;

struct Node {
    string value;
    Node* parent;
    Node* left;
    Node* right;
};

bool search(Node* root, string element) {
    if (root == nullptr) {
        return false;
    }
    if (root->value == element) {
        return true;
    }
    if (element < root->value) {
        return search(root->left, element);
    } else {
        return search(root->right, element);
    }
}

Node* insert(Node* root, Node* element) {
    while (root != nullptr) {
        if (element->value > root->value) {
            if (root->right != nullptr) {
                root = root->right;
            } else {
                element->parent = root;
                root->right = element;
                break;
            }
        } else if (element->value < root->value) {
            if (root->left != nullptr) {
                root = root->left;
            } else {
                element->parent = root;
                root->left = element;
                break;
            }
        }
    }
}

int main() {

    int n;
    cin >> n;

    Node* first_tree = nullptr;
    Node* second_tree = nullptr;
    Node* third_tree = nullptr;

    int boy1 = 0;
    int boy2 = 0;
    int boy3 = 0;

    string first[n];
    string second[n];
    string third[n];

    for (int i = 0; i < n; i++) {
        cin >> first[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> second[i];

    }
    for (int i = 0; i < n; i++) {
        cin >> third[i];

    }



    return 0;
}
