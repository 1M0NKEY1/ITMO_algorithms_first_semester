    #include <iostream>
    #include <vector>

    using namespace std;

    struct element {
        int value;
        int counter;
        element(int value, int counter){
            this->value = value;
            this->counter = counter;
        }
    };

    void sift_down(vector <element> &arr, int size, int i) {
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
            swap(arr[i].value, arr[j].value);
            i = j;
        }
    }

    void sift_up(vector <element> &arr, int i) {
        while (arr[i].value < arr[(i - 1) / 2].value) {
            swap(arr[i].value, arr[(i - 1) / 2].value);
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
            if (S == "push") {
                cin >> value;
                counter++;
                size++;
                heap.emplace_back(value, counter);
                sift_up(heap, size);
            }
            if (S == "extract-min") {
                counter++;
                if (size > 1) {
                    cout << heap[0].value << "\n";
                    swap(heap[0], heap[size - 1]);
                    heap.pop_back();
                    size--;
                    if (size > 1)
                        sift_down(heap, size, 0);
                } else if (size == 1) {
                    cout << heap[0].value << "\n";
                    heap.pop_back();
                    size--;
                } else if (size == 0) {
                    cout << "*\n";
                }
            }
            if (S == "decrease-key") {
                cin >> x >> y;
                counter++;
                for (int i = 0; i < size; i++) {
                    if (heap[i].counter == x) {
                        heap[i].value = y;
                        break;
                    }
                }
                for (int i = 0; i < size / 2; i++) {
                    sift_up(heap, i);
                }
            }
        }
        return 0;
    }
