#include <iostream>
using namespace std;

struct Node {
    char value;
    struct Node *next;
};

struct Node* up = NULL;

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
    char r = up->value;
    if (up != NULL) {
        up = up -> next;
    }
    delete tmp;
    return r;
}

int main() {

    string bracket;
    char br;

    while (getline(cin, bracket)) {

        if (bracket.empty()) {
            break;
        }

//        int counter1 = 0;
//        int counter2 = 0;
        string output = "YES";

        for (int i = 0; i < bracket.length(); i++) {

            br = bracket[i];

            if (br == '(' || br == '[') {
//                counter1++;
                push(br);
            }
//            if (br == '[') {
//                counter2++;
//                push(br);
//            }

//            if (((br == ')' ) || (br == ']' )) && counter1 == 0 && counter2 == 0) {
//                output = "NO";
//                break;
//            }

            if (br == ')') {
                char res = pop();
                if (res == 'q' || res == '[') {
                    output = "NO";
                }
                counter1--;
            }
            if (br == ')' && counter1 < 0) {
                output == "NO";
                break;
            }

            if (br == ']' && counter2 > 0) {
                counter2--;
                pop();
            }
            if (br == ']' && counter2 < 0) {
                output == "NO";
                break;
            }

            if (br != '[' && br != ']' && counter1 == 0 && counter2 == 0) {
                output = "YES";
            } else if (counter1 < 0 && counter2 == 0) {
                output = "NO";
            }

            if (br != '(' && br != ')' && counter2 == 0 && counter1 == 0) {
                output = "YES";
            } else if (counter2 < 0 && counter1 == 0){
                output = "NO";
            }
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
