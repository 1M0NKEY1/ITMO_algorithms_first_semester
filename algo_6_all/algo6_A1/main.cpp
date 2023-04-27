#include <iostream>
#include <vector>

using namespace std;

struct node {
    int key;
    int left;
    int right;
    int height;
    int balance;
};

vector<node> arr;

int height(int i, int left, int right) {
    int max_left = 1;
    int max_right = 1;
    int balance;
    if (left == 0 && right == 0) {
        arr[i].height = 1;
        balance = 0;
    }
    if (right != 0) {
        if (left != 0) {
            balance = arr[right - 1].height - arr[left - 1].height;
        } else {
            balance = arr[right - 1].height - left;
        }
        max_right = height(right - 1, arr[right - 1].left, arr[right - 1].right) + 1;
    }
    if (left != 0) {
        if (right != 0) {
            balance = arr[right - 1].height - arr[left - 1].height;
        } else {
            balance = right - arr[left - 1].height;
        }
        max_left = height(left - 1, arr[left - 1].left, arr[left - 1].right) + 1;
    }
    arr[i].height = max(max_left, max_right);
    arr[i].balance = balance;
    return balance;
}

int balance1(int left, int right) {
    int balance;
    if (left == 0 && right == 0) {
        balance = 0;
    }
    if (left != 0) {
        balance = arr[right - 1].height - arr[left - 1].height;
        balance1(arr[left - 1].left, arr[left - 1].right);
    }
    if (right != 0) {
        balance = arr[right - 1].height - arr[left - 1].height;
        balance1(arr[right - 1].left, arr[right - 1].right);
    }
    return balance;
}

int main() {

    int n;
    cin >> n;

    int key;
    int left;
    int right;

    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> key >> left >> right;
        arr[i].key = key;
        arr[i].left = left;
        arr[i].right = right;
    }

    height(0, arr[0].left, arr[0].right);

    for (int i = 0; i < n; i++) {
        cout << arr[i].balance << "\n";
    }

    return 0;
}
