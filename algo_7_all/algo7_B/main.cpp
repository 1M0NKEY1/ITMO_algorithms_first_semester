#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    int quantity;
    cin >> size >> quantity;

    int sum;
    int max_sum = 0;
    int next = 1;

    vector<int> arr;
    arr.resize(quantity);

    for (int i = 0; i < quantity; i++)
        cin >> arr[i];

    for (int i = 0; i < quantity;) {
        sum = arr[i];

        for (int j = next; j < quantity; j++) {
            sum += arr[j];
            if ((sum > max_sum) && (sum <= size)) {
                max_sum = sum;
            }
        }
        ++next;

        if (next == quantity) {
            ++i;
            if (i != quantity - 1) {
                next = i + 1;
            } else {
                next = i;
            }
        }
    }

    cout << max_sum;

    return 0;
}
