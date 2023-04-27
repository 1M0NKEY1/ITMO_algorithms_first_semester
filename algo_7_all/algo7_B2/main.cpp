#include <iostream>

using namespace std;

int main() {
    int size;
    int quantity;
    cin >> size >> quantity;

    int arr[quantity + 1][size + 1];

    int massive_of_gold[quantity + 1];
    massive_of_gold[0] = 0;
    for (int i = 0; i < quantity; i++) {
        cin >> massive_of_gold[i];
    }

    for (int i = 0; i < size + 1; i++) {
        arr[0][i] = 0;
    }
    for (int i = 0; i < quantity + 1; i++) {
        arr[i][0] = 0;
    }

    for (int k = 1; k <= quantity; k++) {
        for (int s = 1; s <= size; s++) {
            if (s >= massive_of_gold[k - 1]) {
                arr[k][s] = max(arr[k - 1][s], arr[k - 1][s - massive_of_gold[k - 1]] + massive_of_gold[k - 1]);
            } else {
                arr[k][s] = arr[k - 1][s];
            }
        }
    }

    cout << arr[quantity][size];

    return 0;
}
