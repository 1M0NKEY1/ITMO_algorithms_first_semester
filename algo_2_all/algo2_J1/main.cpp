#include <iostream>
#include <vector>

int main() {
    std::vector<int> a;
    int n;
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    for (int i = 2; i < n; i++)
        std::swap(a[i], a[i / 2]);

    for (int i = 0; i < n; i++)
        std::cout << a[i] << ' ';

    return 0;
}
