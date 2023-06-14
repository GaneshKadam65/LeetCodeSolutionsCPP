#include <iostream>
#include <string>

int myAtoi(const std::string& s) {
    int i = 0;
    int n = s.length();
    int sign = 1;
    long result = 0;

    // Ignore leading whitespace
    while (i < n && s[i] == ' ') {
        ++i;
    }

    // Check for optional sign character
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i++] == '+') ? 1 : -1;
    }

    // Convert digits until a non-digit character is encountered
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i++] - '0');

        // Check for integer overflow
        if (result * sign > INT32_MAX) {
            return INT32_MAX;
        }
        if (result * sign < INT32_MIN) {
            return INT32_MIN;
        }
    }

    return result * sign;
}

int main() {
    std::string s = "   -42";
    int result = myAtoi(s);
    std::cout << "Converted integer: " << result << std::endl;

    return 0;
}
