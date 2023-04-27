#include <iostream>
#include <vector>

using namespace std;

struct element {
    int value;
    int counter;
    element(int value, int counter) {
        this->value = value;
        this->counter = counter;
    }
};

void sift_down(vector <element>& arr, int size, int i) {
    while (2 * i + 1 < size) {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int j = i;
        if (left_child < size && arr[left_child].value < arr[j].value) {
            j = left_child;
        }
        if (right_child < size && arr[right_child].value < arr[j].value) {
            j = right_child;
        }
        if (arr[i].value <= arr[j].value) {
            break;
        }
        swap(arr[i], arr[j]);
        i = j;
    }
}

void sift_up(vector <element>& arr, int i) {
    while (arr[i].value < arr[(i - 1) / 2].value && i >= 0) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    int value;
    int x;
    int y;
    vector <element> heap;
    int size = 0;
    int counter = 0;
    string S;
    while (cin >> S) {
        counter++;
        if (S == "push") {
            cin >> value;
            heap.emplace_back(value, counter);
            sift_up(heap, size);
            ++size;
        }
        if (S == "extract-min") {
            if (size > 0) {
                cout << heap[0].value << "\n";
                swap(heap[0], heap[size - 1]);
                heap.pop_back();
                --size;
                sift_down(heap, size, 0);
            }
            else {
                cout << "*\n";
            }
        }
        if (S == "decrease-key") {
            cin >> x >> y;
            for (int i = 0; i < size; i++) {
                if (heap[i].counter == x) {
                    heap[i].value = y;
                    sift_up(heap, i);
                    break;
                }
            }
        }
    }
    return 0;
}