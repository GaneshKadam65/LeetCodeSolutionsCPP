#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0) {
        return false;  // Negative numbers are not palindromic
    }
    
    long long original = x;
    long long reversed = 0;
    
    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }
    
    return original == reversed;
}

int main() {
    int x = 12321;
    bool palindrome = isPalindrome(x);
    if (palindrome) {
        cout << x << " is a palindrome." << endl;
    } else {
        cout << x << " is not a palindrome." << endl;
    }
    
    return 0;
}
