#include <iostream>

using namespace std;

struct Node {
    int value;
    struct Node *next;
};

struct Node* up = NULL;

void push(int value) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> value = value;
    new_node -> next = up;
    up = new_node;
}

int pop() {
    Node* tmp = up;
    int p = tmp -> value;
    if (up != NULL) {
        up = up -> next;
    }
    delete tmp;
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char symbol;
    int value;
    int count = 0;

    int n;
    cin >> n;
    int *array = new int [n];

    for (int i = 0; i < n; i++) {
        cin >> symbol;
        if (symbol == '+') {
            cin >> value;
            push(value);
        } else if (symbol == '-') {
            array[count] = pop();
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        cout << array[i] << "\n";
    }

    delete [] array;

    return 0;
}
