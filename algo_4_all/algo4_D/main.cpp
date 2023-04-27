#include <iostream>

using namespace std;

int get_max(int array[], int length) {
    int max = 0;
    for (int i = 0; i < length; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    return max;
}

void sort(int array[], int length, int place) {
    int max_index = 10;
    int sorted_array[length];
    int index_array[max_index];

    for (int i = 0; i < max_index; i++) {
        index_array[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        index_array[(array[i] / place) % 10]++;
    }

    for (int i = 1; i < max_index; i++) {
        index_array[i] += index_array[i - 1];
    }

    for (int i = length - 1; i >= 0; i--) {
        sorted_array[index_array[(array[i] / place) % 10] - 1] = array[i];
        index_array[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < length; i++) {
        array[i] = sorted_array[i];
    }
}

int main() {

    int n;
//    int m;
    int k;
    cin >> n >> k;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int max = get_max(array, n);
    for (int place = k; max / place > 0; place *= 10) {
        sort(array, n, place);
    }

    for (int i = 0; i < n; i++) {
        cout << array[i] << "\n";
    }

    return 0;
}
