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
    int result = up -> value;
    if (up != nullptr) {
        up = up -> next;
    }
    delete tmp;
    return result;
}

bool empty() {
    Node *tmp = up;
    return tmp == NULL;
}


int main() {

    string sentence;
    char symbol;
    int number;

    int element1 = 0;
    int element2 = 0;

    while (getline(cin, sentence)) {

        if (sentence.empty()) {
            break;
        }

        for (int i = 0; i < sentence.length(); i++) {

            symbol = sentence[i];

            if (symbol == ' ') {
                continue;
            }

            if (isdigit(sentence[i])) {
                number = sentence[i]-'0';
                push(number);
            }

            switch (symbol) {
                case '+':
                    element1 = pop();
                    element2 = pop();
                    push(element1 + element2);
                    break;
                case '-':
                    element1 = pop();
                    element2 = pop();
                    push(element2 - element1);
                    break;
                case '*':
                    element1 = pop();
                    element2 = pop();
                    push(element1 * element2);
                    break;
            }
        }

//        if (!empty()) {
//            cout << output;
//        }
        cout << pop();
        break;
    }

    return 0;
}
