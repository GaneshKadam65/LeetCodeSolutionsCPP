#include <iostream>
#include <vector>
#include <algorithm>

bool canFormArithmeticProgression(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());  // Sort the array in ascending order

    int diff = arr[1] - arr[0];  // Calculate the difference between the first two elements

    for (int i = 2; i < arr.size(); i++) {
        if (arr[i] - arr[i-1] != diff) {
            return false;  // The difference between consecutive elements is not the same
        }
    }

    return true;  // All differences are the same, so it forms an arithmetic progression
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7};  // Example input

    if (canFormArithmeticProgression(arr)) {
        std::cout << "The array can be rearranged to form an arithmetic progression." << std::endl;
    } else {
        std::cout << "The array cannot be rearranged to form an arithmetic progression." << std::endl;
    }

    return 0;
}
