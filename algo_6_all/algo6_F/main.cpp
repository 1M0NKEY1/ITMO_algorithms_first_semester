#include <iostream>

using namespace std;

struct Node {
    string key;
    int height;
    Node* left;
    Node* right;
    Node(string value) {
            key = value;
            left = nullptr;
            right = nullptr;
            height = 1;
    }
};

struct Node1 {
    char symbol;
    int height;
    Node1* left;
    Node1* right;
    Node1(char s) {
        symbol = s;
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

Node* insert_element(Node* root, string key) {
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

bool check(Node* root, string key) {
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




int height_char(Node1* root) {
    if (root != nullptr) {
        return root->height;
    } else {
        return 0;
    }
}

int balance_factor_char(Node1* root) {
    return height_char(root->right) - height_char(root->left);
}

void fixed_height_char(Node1* root) {
    int left_height = height_char(root->left);
    int right_height = height_char(root->right);
    if (left_height > right_height) {
        root->height = left_height + 1;
    } else {
        root->height = right_height + 1;
    }
}

Node1* left_rotation_char(Node1* root) {
    Node1* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    fixed_height_char(root);
    fixed_height_char(tmp);
    return tmp;
}

Node1* right_rotation_char(Node1* root) {
    Node1* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    fixed_height_char(root);
    fixed_height_char(tmp);
    return tmp;
}

Node1* balance_char(Node1* root) {
    fixed_height_char(root);
    if (balance_factor_char(root) > 1) {
        if (balance_factor_char(root->right) < 0) {
            root->right = right_rotation_char(root->right);
        }
        return left_rotation_char(root);
    }
    if (balance_factor_char(root) < -1) {
        if (balance_factor_char(root->left) > 0) {
            root->left = left_rotation_char(root->left);
        }
        return right_rotation_char(root);
    }
    return root;
}

Node1* insert_char(Node1* root, char key) {
    if (root == nullptr) {
        return new Node1(key);
    }
    if (key < root->symbol) {
        root->left = insert_char(root->left, key);
    } else {
        root->right = insert_char(root->right, key);
    }
    return balance_char(root);
}

bool check_char(Node1* root, char key) {
    if (root == nullptr) {
        return false;
    }
    if (root->symbol == key) {
        return true;
    }
    if (key < root->symbol) {
        return check_char(root->left, key);
    } else if (key >= root->symbol) {
        return check_char(root->right, key);
    }
}


int main() {

    Node* avl_tree = nullptr;

    int n;
    cin >> n;

    int counter = 0;

    string book[n];
    string tmp;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (!check(avl_tree, tmp)) {
            avl_tree = insert_element(avl_tree, tmp);
        } else {
            book[i] = tmp;
        }
    }

//    for (int i = 0; i < n; i++) {
//        Node1* extra_tree = nullptr;
//        string inside_string = book[i];
//        for (int j = 0; j < book[i].size(); j++) {
//            if (!check_char(extra_tree, inside_string[j])) {
//                extra_tree = insert_char(extra_tree, inside_string[j]);
//                counter++;
//            }
//        }
//    }

    for (int i = 0; i < n; i++) {
        Node* extra_tree = nullptr;
        string inside_string = book[i];
        for (int j = 0; j < book[i].size(); j++) {
            extra_tree = insert_element(extra_tree, string(1, inside_string[j]));
            counter++;
        }
    }

    cout << counter << "\n";

    return 0;
}
