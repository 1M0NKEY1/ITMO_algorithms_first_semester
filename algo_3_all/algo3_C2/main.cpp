#include <iostream>
using namespace std;

struct Node {
    char value;
    struct Node *next;
};

struct Node* up = nullptr;


void push(char value) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> value = value;
    new_node -> next = up;
    up = new_node;
}

char pop() {
    Node* tmp = up;
    if (tmp == nullptr) {
        return 'q';
    }
    char result = up -> value;
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

    string bracket;
    char br;

    while (getline(cin, bracket)) {

        if (bracket.empty()) {
            break;
        }

        string output = "YES";

        for (int i = 0; i < bracket.length(); i++) {

            br = bracket[i];

            if (br == '(' || br == '[') {
                push(br);
            }

            if (br == ')') {
                char res = pop();
                if (res == 'q' || res == '[') {
                    output = "NO";
                    pop();
                }
            }

            if (br == ']') {
                char res = pop();
                if (res == 'q' || res == '(') {
                    output = "NO";
                    pop();
                }
            }
        }

        if (!empty()) {
            output = "NO";
        }

        if (br == '(' || br == '[') {
            pop();
            char result = pop();
            if (result == 'q') {
                output = "NO";
            }
        }

        while (!empty()) {
            pop();
        }

        if (output == "YES") {
            cout << output << "\n";
            continue;
        }
        if (output == "NO") {
            cout << output << "\n";
        }
    }
    return 0;
}
