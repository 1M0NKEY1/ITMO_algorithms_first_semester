#include <iostream>

using namespace std;

void left_bin(int arr[], int x[], int n, int i) {
    int left = 0;
    int right = n - 1;
    bool f = false;
    int middle;

    while (left <= right && !f) {
        middle = (left + right) / 2;
        if (arr[middle] == x[i] && (middle == 0 || arr[middle - 1] < arr[middle])) {
            f = true;
        } else {
            if (arr[middle] >= x[i]) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
    }

    if (!f) {
        cout << middle + 1 << ' ';
    } else {
        cout << -1 << ' ' << -1 << '\n';
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
        cin >> array_counts[counts_of_numbers];
    }

    for (int i = 0; i < counts_of_numbers; i++) {
        left_bin(array, array_counts, length, counts_of_numbers);
    }
    return 0;
}
