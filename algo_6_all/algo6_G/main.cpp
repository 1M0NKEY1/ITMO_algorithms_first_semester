#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

void build(int current, int left_t, int right_t) {
    if (left_t == right_t) {
        arr[current] = 0;
    } else {
        int tmp = (left_t + right_t) / 2;
        build(2 * current, left_t, tmp);
        build(2 * current + 1, tmp + 1, right_t);
        arr[current] = arr[2 * current] + arr[2 * current + 1];
    }
}

void update(int current, int left_t, int right_t, int position, int new_value) {
    if (left_t == right_t) {
        if (arr[current] + new_value >= 0) {
            arr[current] += new_value;
        } else {
            arr[current] = 0;
        }
    } else {
        int tmp = (left_t + right_t) / 2;
        if (position <= tmp) {
            update(2 * current, left_t, tmp, position, new_value);
        } else {
            update(2 * current + 1, tmp + 1, right_t, position, new_value);
        }
        arr[current] = arr[2 * current] + arr[2 * current + 1];
    }
}

int amount(int current, int left_t, int right_t, int left, int right) {
    if (left > right) {
        return 0;
    }
    if (left == left_t && right == right_t) {
        return arr[current];
    }
    int tmp = (left_t + right_t) / 2;
    return amount(2 * current, left_t, tmp, left, min(right, tmp))
           + amount(2 * current + 1, tmp + 1, right_t, max(left, tmp + 1), right);
}

int main() {

    cin >> n;
    int quantity;
    cin >> quantity;
    arr.resize(4 * n);

    char symbol;
    int i;
    int piece;
    int left, right;

    build(1, 0, n - 1);

    for (int j = 0; j < quantity; j++) {
        cin >> symbol;
        switch (symbol) {
            case '+':
                cin >> i >> piece;
                update(1, 0, n - 1, i - 1, piece);
                break;

            case '-':
                cin >> i >> piece;
                update(1, 0, n - 1, i - 1, -piece);
                break;

            case '?':
                cin >> left >> right;
                cout << amount(1, 0, n - 1, left - 1, right - 1) << "\n";
                break;
        }
    }
    return 0;
}
