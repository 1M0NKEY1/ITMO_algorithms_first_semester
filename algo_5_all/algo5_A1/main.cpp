#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int element;
    int left;
    int right;

    int magic_number = 0;

    int counter1 = 1;
    int counter2 = 1;

    if (n == 0) {
        cout << 0;
    } else {
        for (int i = 1; i < n + 1; i++) {
            cin >> element >> left >> right;
            if (counter1 == 1 && counter2 == 1 && left != 0 && right != 0) {
                magic_number = 1;
            }
            if (left != 0) {
                counter1++;
                if (right == 0) {
                    counter2++;
                }
            }
            if (right != 0) {
                counter2++;
                if (left == 0) {
                    counter1++;
                }
            }
        }

        int max_counter = max(counter1, counter2);
        if (max_counter > n) {
            if (magic_number == 1)
                cout << (max_counter - (max_counter - n)) / 2;
            else {
                cout << max_counter - (max_counter - n);
            }
        } else {
            if (magic_number == 1) {
                cout << max_counter / 2;
            } else {
                cout << max_counter;
            }

        }

    }
    return 0;
}
