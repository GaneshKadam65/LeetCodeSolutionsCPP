#include <iostream>
#include <vector>

bool isMatch(const std::string& s, const std::string& p) {
    int m = s.length();
    int n = p.length();

    // Create a 2D table to store the matching information
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

    // An empty pattern matches an empty string
    dp[0][0] = true;

    // Handle patterns with '*' as the first character
    for (int j = 2; j <= n; j += 2) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    // Fill in the rest of the table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                // Characters match, or pattern is '.'
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                // Handle '*' case
                if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                    // Match zero or more preceding element
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                } else {
                    // Ignore preceding element
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::string s = "aa";
    std::string p = "a*";
    bool result = isMatch(s, p);
    std::cout << "Matching result: " << std::boolalpha << result << std::endl;

    return 0;
}
