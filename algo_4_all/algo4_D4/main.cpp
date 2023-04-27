#include <iostream>

using namespace std;

void sort(string array[], int length, int size, int phase) {
    int max_index = 26;
    string sorted_array[length];
    int index_array[max_index];

    phase = size - phase - 1;

    for (int i = 0; i < max_index; i++) {
        index_array[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        index_array[int(array[i][phase]) - 97]++;
    }

    for (int i = 1; i < max_index; i++) {
        index_array[i] += index_array[i - 1];
    }

    for (int i = length - 1; i >= 0; i--) {
        sorted_array[index_array[int(array[i][phase]) - 97] - 1] = array[i];
        index_array[int(array[i][phase]) - 97]--;
    }

    for (int i = 0; i < length; i++) {
        array[i] = sorted_array[i];
    }

}

int main() {

    int length;
    int size;
    int phase;
    cin >> length >> size >> phase;
    string array[length];
    for (int i = 0; i < length; i++) {
        cin >> array[i];
    }


    for (int i = 0; i < phase; i++) {
        sort(array, length, size, i);
    }


    for (int i = 0; i < length; i++) {
        cout << array[i] << "\n";
    }

    return 0;
}
