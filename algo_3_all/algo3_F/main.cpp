#include <iostream>


using namespace std;

int left_bin_search(int array[], int x[], int length, int i) {
    int left = -1;
    int right = length;
    while (right > left + 1) {
        int middle = (left + right) / 2;
        if (array[middle] < x[i]) {
            left = middle;
        } else {
            right = middle;
        }
    }
    if (right < length && array[right] == x[i]) {
        return right;
    } else {
        return  -2;
    }
}

int right_bin_search(int array[], int x[], int length, int i) {
    int left = -1;
    int right = length;
    while (right > left + 1) {
        int middle = (left + right) / 2;
        if (array[middle] <= x[i]) {
            left = middle;
        } else {
            right = middle;
        }
    }
    if (left < length && array[left] == x[i]) {
        return left;
    } else {
        return  -2;
    }
}

int main() {
    int length;
    cin >> length;
    int array[length];
    for (int i = 0; i < length; i++) {
        cin >> array[i];
    }

    int counts_of_numbers;
    cin >> counts_of_numbers;
    int array_counts[counts_of_numbers];
    for (int i = 0; i < counts_of_numbers; i++) {
        cin >> array_counts[i];
    }

    for (int i = 0; i < counts_of_numbers; i++) {
        cout << left_bin_search(array, array_counts, length, i) + 1 << ' ' << right_bin_search(array, array_counts, length, i) + 1 << "\n";
    }

    return 0;
}