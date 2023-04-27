#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int element;
    int left;
    int right;
    int height = 0;

    int array[n];
    for (int i = 0; i < n; i++) {
        array[i] = 0;
    }

    if (n == 0) {
        cout << 0;
    } else {
        for (int i = 0; i < n; i++) {
            cin >> element >> left >> right;

            if (left != 0) {
                array[left - 1] = array[i] + 1;
                if (height < array[left - 1]) {
                    height = array[left - 1];
                }
            }

            if (right != 0) {
                array[right - 1] = array[i] + 1;
                if (height < array[right - 1]) {
                    height = array[right - 1];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << array[i] << ' ';
        }
        cout << "\n" << height;
    }

    return 0;
}
