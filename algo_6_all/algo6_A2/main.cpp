#include <iostream>
#include <vector>

using namespace std;

struct node {
    int key;
    int left;
    int right;
    int height;
};

vector<node> arr;

int height(int i, int left, int right) {
    int max_left = 1;
    int max_right = 1;
    if (arr[i].right == 0 && arr[i].left == 0) {
        arr[i].height = 1;
    }
    if (arr[i].right != 0) {
        max_right = height(right - 1, arr[right - 1].left, arr[right - 1].right) + 1;
    }
    if (arr[i].left != 0) {
        max_left = height(left - 1, arr[left - 1].left, arr[left - 1].right) + 1;
    }

    arr[i].height = max(max_left, max_right);

    return max(max_left, max_right);
}

int balance1(int left, int right) {
    int balance;
    if (left == 0 && right == 0) {
        balance = 0;
    }
    if (left != 0) {
        balance = arr[right - 1].height - arr[left - 1].height;

    }
    if (right != 0) {
        balance = arr[right - 1].height - arr[left - 1].height;

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
        cout << balance1(arr[i].left, arr[i].right) << "\n";
    }

    return 0;
}