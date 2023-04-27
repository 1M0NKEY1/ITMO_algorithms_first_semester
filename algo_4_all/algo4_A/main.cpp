#include <iostream>

using namespace std;

int main() {
    int length;
    cin >> length;
    int heap[length];
    string output;

    for (int i = 0; i < length; i++) {
        cin >> heap[i];
    }

    for (int i = 0; i < length; i++) {
        if ((2 * i + 1 < length)) {
            if (heap[i] <= heap[2 * i + 1]) {
                output = "YES";
            } else {
                output = "NO";
                break;
            }
        }
        if (2 * i + 2 < length) {
            if (heap[i] <= heap[2 * i + 2]) {
                output = "YES";
            } else {
                output = "NO";
                break;
            }
        }
    }

    cout << output << "\n";

    return 0;
}
