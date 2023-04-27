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

int height(Node* root) {
    if (root != nullptr) {
        return root->height;
    } else {
        return 0;
    }
}

int balance_factor(Node* root) {
    return height(root->right) - height(root->left);
}

void fixed_height(Node* root) {
    int left_height = height(root->left);
    int right_height = height(root->right);
    if (left_height > right_height) {
        root->height = left_height + 1;
    } else {
        root->height = right_height + 1;
    }
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

Node* left_rotation(Node* root) {
    Node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    fixed_height(root);
    fixed_height(tmp);
    return tmp;
}

Node* right_rotation(Node* root) {
    Node* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    fixed_height(root);
    fixed_height(tmp);
    return tmp;
}

Node* balance(Node* root) {
    fixed_height(root);
    if (balance_factor(root) > 1) {
        if (balance_factor(root->right) < 0) {
            root->right = right_rotation(root->right);
        }
        return left_rotation(root);
    }
    if (balance_factor(root) < -1) {
        if (balance_factor(root->left) > 0) {
            root->left = left_rotation(root->left);
        }
        return right_rotation(root);
    }
    return root;
}

Node* insert_element(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert_element(root->left, key);
    } else if (key >= root->key) {
        root->right = insert_element(root->right, key);
    }
    return balance(root);
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
        root->key = previous(root->left, deleted_key)->key;
        root->left = del(root->left, root->key);
    } else {
        if (root->left != nullptr) {
            root = root->left;
            return balance(root);
        } else if (root->right != nullptr) {
            root = root->right;
            return balance(root);
        } else {
            root = nullptr;
            return nullptr;
        }
    }
    return balance(root);
}

bool check(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->key == key) {
        return true;
    }
    if (key < root->key) {
        return check(root->left, key);
    } else if (key >= root->key) {
        return check(root->right, key);
    }
}


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    cin >> n;

    int key;

    char operation;

    Node* tree = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> operation;
        switch (operation) {
            case 'A':
                cin >> key;
                if (!check(tree, key)) {
                    tree = insert_element(tree, key);
                    cout << balance_factor(tree) << "\n";
                } else {
                    cout << balance_factor(tree) << "\n";
                }
                break;
            case 'D':
                cin >> key;
                if (check(tree, key)) {
                    tree = del(tree, key);
                }
                if (tree != nullptr) {
                    cout << balance_factor(tree) << "\n";
                } else {
                    cout << 0 << "\n";
                }
                break;
            case 'C':
                cin >> key;
                if (check(tree, key)) {
                    cout << "Y" << "\n";
                } else {
                    cout << "N" << "\n";
                }
                break;
        }
    }
    return 0;
}
