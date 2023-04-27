#include <iostream>

using namespace std;

struct Node {
    int value;
    int max_value;
    struct Node *next;
};

struct Node* up = NULL;

void push(int value, int max_value) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> value = value;
    new_node -> max_value = max_value;
    new_node -> next = up;
    up = new_node;
}

void pop() {
    Node* tmp = up;
    up = tmp -> next;
    delete tmp;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string symbol;
    int value;
    int max_value = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> symbol;
        if (symbol == "+") {
            cin >> value;
            if (max_value < value) {
                max_value = value;
                push(value, value);
            } else {
                push(value, max_value);
            }
        }
        if (symbol == "-") {
            pop();
            max_value = up -> max_value;
        }
        if (symbol == "max") {
            cout << max_value << "\n";
        }
    }
    return 0;
}
