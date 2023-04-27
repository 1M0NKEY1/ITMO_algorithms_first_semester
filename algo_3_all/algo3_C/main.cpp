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

void pop() {
    Node* tmp = up;
    if (up != NULL) {
        up = up -> next;
    }
    delete tmp;
}

int main() {

    string bracket;
    char br;

    while (getline(cin, bracket)) {

        if (bracket.empty()) {
            break;
        }

        int counter1 = 0;
        int counter2 = 0;
        int anticounter1 = 0;
        int anticounter2 = 0;
        string output = "NO";

        for (int i = 0; i < bracket.length(); i++) {

            br = bracket[i];

            if (br == '(') {
                counter1++;
                push(br);
            }
            if (br == '[') {
                counter2++;
                push(br);
            }

            if (((br == ')' ) || (br == ']' )) && counter1 == 0 && counter2 == 0) {
                cout << output << "\n";
                break;
            }

            if (br == ')' && anticounter1 <= counter1 && counter1 != 0) {
                anticounter1++;
                pop();
            }
            if (br == ')' && anticounter1 > counter1) {
                cout << "NO" << "\n";
                break;
            }

            if (br == ']' && anticounter2 <= counter2 && counter2 != 0) {
                anticounter2++;
                pop();
            }
            if (br == ']' && anticounter2 > counter2) {
                cout << "NO" << "\n";
                break;
            }
        }

        if (counter1 == 0 && anticounter1 == 0 && anticounter2 != 0) {
            output = "YES";
        } else if (counter2 == 0 && anticounter2 == 0 && anticounter1 != 0) {
            output = "YES";
        } else {
            output = "NO";
        }

        if (output == "YES") {
            cout << output << "\n";
            break;
        }
    }



    return 0;
}
