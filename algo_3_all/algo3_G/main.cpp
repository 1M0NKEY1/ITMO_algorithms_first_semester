#include <iostream>
#include <vector>

using namespace std;

int n;
vector <double> height;


double bin_search(double accuracy_rate) {
    double left = 0;
    double right = height[0];
    while (right - left > accuracy_rate) {
        height[1] = (left + right) / 2;
        bool floor = false;
        for (int i = 2; i < n; i++) {
            height[i] = 2 * height[i - 1] - height[i - 2] + 2;
            if (height[i] < 0) {
                floor = true;
                break;
            }
        }
        if (!floor) {
            right = height[1];
        } else {
            left = height[1];
        }
    }
    return height[n - 1];
}

int main() {

    cin >> n;
    height.resize(n);
    double accuracy_rate = 0.00003 / n; // точность

    cin >> height[0];

    double B = bin_search(accuracy_rate);
    cout << fixed;
    cout.precision(2);
    cout << B;
    return 0;
}