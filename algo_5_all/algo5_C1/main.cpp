#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int key;
    int left;
    int right;
};

vector <Node> arr;
int x;
int n;

void create_tree_left(int i, int left, int right) {
    if (left == 0) {
        if (right == 0) {
            if (arr[i].key == 0) {
                if (x <= n) {
                    arr[i].key = x;
                    x += 1;
                }

            }
            return;
        } else {
            if (arr[i].key == 0) {
                if (x <= n) {
                    arr[i].key = x;
                    x += 1;
                }
            }
        }
    }
    if (left != 0) {
        create_tree_left(left - 1, arr[left - 1].left , arr[left - 1].right);
        if (x <= n) {
            arr[i].key = x;
            x += 1;
        }
    }
    if (right != 0) {
        create_tree_left(right - 1, arr[right - 1].left, arr[right - 1].right);
    }
}

int main() {
    cin >> n;
    x = 1;
    int left;
    int right;
    arr.resize(n);
    for (int i = 0; i < n; i++) { // это правильно
        cin >> left >> right;
        arr[i].left = left;
        arr[i].right = right;
    }

    create_tree_left(0, arr[0].left, arr[0].right);

    for (int i = 0; i < n; i++) {
        cout << arr[i].key << ' ';
    }
    return 0;
}
