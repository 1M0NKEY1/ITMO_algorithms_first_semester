#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int S, N;
    std::cin >> S >> N;
    std::vector<int> wightOfGold;
    wightOfGold.resize(N+1);
    for (int i = 1; i < wightOfGold.size(); i++){
        std::cin >> wightOfGold[i];
    }
    wightOfGold[0] = 0;
    for (int i = 0; i < wightOfGold.size(); i++){
        std::cout << wightOfGold[i];
    }

    int arrForDynamics[wightOfGold.size()][S];
    for (int i = 0; i < wightOfGold.size(); i++) {
        for (int j = 0; j < S; j++) {
            arrForDynamics[i][j] = 0;
        }
    }
    for (int i = 0; i < wightOfGold.size(); i++) {
        for (int j = 0; j < S; j++) {
            std::cout << arrForDynamics[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    for (int i = 0; i < S; i++){
        arrForDynamics[0][i] = 0;
    }

    for (int i = 1; i <  wightOfGold.size(); i++) {
        for (int j = 0; j < S; j++){
            if (j >= wightOfGold[i])
                arrForDynamics[i][j] = std::max(arrForDynamics[i - 1][j], arrForDynamics[i - 1][j - wightOfGold[i]] + wightOfGold[i]);
            else
                arrForDynamics[i][j] = arrForDynamics[i - 1][j];
        }
    }
    for (int i = 0; i < wightOfGold.size(); i++) {
        for (int j = 0; j < S; j++) {
            std::cout << arrForDynamics[i][j] << ' ';
        }
        std::cout << '\n';
    }

    std::cout << arrForDynamics[wightOfGold.size()-1][S-1];

    return 0;
}