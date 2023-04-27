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


//void create_tree_left(int i, int left, int right) {
//    if (left == 0) {
//        if (right == 0) {
//            if (arr[i].key == 0) {
//                arr[i].key = x;
//                x++;
//            }
//            return;
//        } else {
//            if (arr[i].key == 0) {
//                arr[i].key = x;
//                x++;
//            }
//        }
//    }
//    if (left != 0) {
//        create_tree_left(i, arr[left - 1].left , right);
//        arr[i].key = x;
//        x++;
//    }
//    if (right != 0) {
//        create_tree_left(i, left, arr[right - 1].right);
//    }
//}

void create_tree_left(int i) {
    if (arr[i].left == -1) {
        if (arr[i].right == -1) {
            if (arr[i].key == 0) {
                arr[i].key = x;
                x += 1;
            }
            return;
        } else {
            if (arr[i].key == 0) {
                arr[i].key = x;
                x += 1;
            }
        }
    }
    if (arr[i].left != -1) {
        create_tree_left(arr[i].left);
        arr[i].key = x;
        x += 1;
    }
    if (arr[i].right != -1) {
        create_tree_left(arr[i].right);
    }
}

int main() {
    int n;
    cin >> n;
    x = 1;
    int left;
    int right;
    arr.resize(n);
    for (int i = 0; i < n; i++) { // это правильно
        cin >> left >> right;
        arr[i].left = left;
        arr[i].right = right;
        --arr[i].left;
        --arr[i].right;
    }

    for (int i = 0; i < n; i++) {
        create_tree_left(i);
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i].key << ' ';
    }

    return 0;
}
