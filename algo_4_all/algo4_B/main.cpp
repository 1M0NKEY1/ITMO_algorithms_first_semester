#include <iostream>

using namespace std;

void create_heap(int heap[], int i, int length) {
    int max_i = i;
    while (true) {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        if (left_child < length && heap[left_child] > heap[max_i]) {
            max_i = left_child;
        }
        if (right_child < length && heap[right_child] > heap[max_i]) {
            max_i = right_child;
        }
        if (max_i == i) {
            break;
        } else {
            swap(heap[max_i], heap[i]);
            i = max_i;
        }
    }
}



int main() {

    int length;
    cin >> length;
    int heap[length];
    for (int i = 0; i < length; i++) {
        cin >> heap[i];
    }

    for (int i = length / 2; i >= 0; i--) {
        create_heap(heap, i, length);
    }
    for (int i = length - 1; i >= 1; i--) {
        swap(heap[0], heap[i]);
        create_heap(heap, 0, i);
    }

    for (int i = 0; i < length; i++) {
        cout << heap[i] << ' ';
    }

    return 0;
}
