#include <iostream>

using namespace std;

struct Node1 {
    int value1;
    struct Node1 *next1;
};

struct Node1* up1 = NULL;

void push1(int value) {
    struct Node1* new_node1 = (struct Node1*) malloc(sizeof(struct Node1));
    new_node1 -> value1 = value;
    new_node1 -> next1 = up1;
    up1 = new_node1;
}

int pop1() {
    Node1* tmp1 = up1;
    int p1 = tmp1 -> value1;
    if (up1 != NULL) {
        up1 = up1 -> next1;
    }
    delete tmp1;
    return p1;
}

struct Node2 {
    int value2;
    struct Node2 *next2;
};

struct Node2* up2 = NULL;

void push2(int value) {
    struct Node2* new_node2 = (struct Node2*) malloc(sizeof(struct Node2));
    new_node2 -> value2 = value;
    new_node2 -> next2 = up2;
    up2 = new_node2;
}

int pop2() {
    Node2* tmp2 = up2;
    int p2 = tmp2 -> value2;
    if (up2 != NULL) {
        up2 = up2 -> next2;
    }
    delete tmp2;
    return p2;
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
        if (symbol == '+' || symbol == '*') {

        }
    }

    return 0;
}
