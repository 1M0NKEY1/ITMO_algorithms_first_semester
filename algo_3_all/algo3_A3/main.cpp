#include <iostream>
using namespace std;

struct Qnode {
    int value;
    Qnode* next;
    Qnode(int d) {
        value = d;
        next = NULL;
    }
};

struct Queue {
    Qnode *head;
    Qnode *tail;
    Queue() {head = tail = NULL;}

    void push(int x) {
        Qnode* tmp = new Qnode(x);
        if (tail == NULL) {
            head = tail = tmp;
            return;
        }
        tail -> next = tmp;
        tail = tmp;
    }

    int pop() {
        Qnode* tmp = head;
        int p = tmp -> value;
        head = head -> next;
        if (head == NULL) {
            tail = NULL;
        }
        delete (tmp);
        return p;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Queue q;

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
            q.push(value);
        } else if (symbol == '-') {
            array[count] = q.pop();
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        cout << array[i] << "\n";
    }

    delete [] array;
    return 0;
}
