#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int i = 0;

void postorder(int minimum, int maximum) {
    if ((arr[i] >= minimum) && (arr[i] <= maximum) && (i <= arr.size())) {
        int cur = arr[i];
        ++i;
        postorder(minimum, cur);
        postorder(cur, maximum);
        cout << cur << ' ';
    }
}

int main() {
    int n;
    cin >> n;

    int minimum = INT_MIN;
    int maximum = INT_MAX;

    arr.resize(n);

    for (int j = 0; j < n; j++) {
        cin >> arr[j];
    }

    postorder(minimum, maximum);

    return 0;
}
