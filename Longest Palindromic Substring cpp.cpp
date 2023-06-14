#include <iostream>
#include <string>

std::string longestPalindrome(const std::string& s) {
    int start = 0;
    int maxLength = 1;
    int n = s.length();

    // Create a table to store the palindrome information
    bool dp[1000][1000] = {false};

    // All individual characters are palindromes of length 1
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    // Check for palindromes of length 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for palindromes of length greater than 2
    for (int k = 3; k <= n; ++k) {
        for (int i = 0; i < n - k + 1; ++i) {
            int j = i + k - 1;

            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;

                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    // Extract the longest palindromic substring
    return s.substr(start, maxLength);
}

int main() {
    std::string s = "babad";
    std::string longestPalindromicSubstr = longestPalindrome(s);
    std::cout << "Longest palindromic substring: " << longestPalindromicSubstr << std::endl;

    return 0;
}
