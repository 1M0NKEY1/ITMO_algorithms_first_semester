#include <iostream>
#include <vector>

using namespace std;

vector<int> func(vector<int> arr) {
    int n = arr.size();
    vector<int> d(n, 1);
    vector<int> previous(n, -1);
    int position = 0;


    for (int i = 0; i <= n - 1; i++) {
        d[i] = 1;
        previous[i] = -1;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] < arr[i] && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                previous[i] = j;
            }
        }
    }

    int length = d[0];
    for (int i = 0; i <= n - 1; i++) {
        if (d[i] > length) {
            position = i;
            length = d[i];
        }
    }

    vector<int> output;
    while (position > -1) {
        output.push_back(arr[position]);
        position = previous[position];
    }

    return output;
}

int main() {
    int n;
    cin >> n;

    vector<int> massive;
    massive.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> massive[i];
    }

    int size = func(massive).size();

    vector<int> new_massive = func(massive);

    cout << size << "\n";
    for (int i = size - 1; i > -1; i--) {
        cout << new_massive[i] << ' ';
    }
    return 0;
}
