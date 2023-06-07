#include <iostream>

int minFlips(int a, int b, int c) {
    int flips = 0;
    for (int i = 0; i < 32; i++) {
        int bitA = (a >> i) & 1;  // Get i-th bit of a
        int bitB = (b >> i) & 1;  // Get i-th bit of b
        int bitC = (c >> i) & 1;  // Get i-th bit of c

        if ((bitA | bitB) != bitC) {
            if (bitC == 0) {
                flips += bitA + bitB;  // Flips both bits if bitC is 0
            } else {
                flips += 1;  // Flip any one bit if bitC is 1
            }
        }
    }
    return flips;
}

int main() {
    int a, b, c;
    std::cout << "Enter the values of a, b, and c: ";
    std::cin >> a >> b >> c;
    
    int minFlipsRequired = minFlips(a, b, c);
    std::cout << "Minimum flips required: " << minFlipsRequired << std::endl;
    
    return 0;
}
