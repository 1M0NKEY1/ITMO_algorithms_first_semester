#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int key;
    int left;
    int right;
};

vector<Node> arr;
bool output = true;

void check_tree(int i, int minimum, int maximum) {
    if (arr[i].key <= minimum || arr[i].key >= maximum) {
        output = false;
        return;
    }
    if (arr[i].left != 0) {
        check_tree(arr[i].left - 1, minimum, arr[i].key);
    }
    if (arr[i].right != 0) {
        check_tree(arr[i].right - 1, arr[i].key, maximum);
    }
}

int main() {

    int n;
    cin >> n;

    int j = 0;
    int minimum = INT_MIN;
    int maximum = INT_MAX;

    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].key >> arr[i].left >> arr[i].right;
    }

    if (n != 0) { // Выполнять, только если дерево не пустое
        check_tree(j, minimum, maximum);
    }

    if (output || n == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
