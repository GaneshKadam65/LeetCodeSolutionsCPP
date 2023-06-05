#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
    int result = 0;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        int value = romanValues[s[i]];
        
        if (i < n - 1 && value < romanValues[s[i + 1]]) {
            result -= value;
        } else {
            result += value;
        }
    }
    
    return result;
}

int main() {
    string s = "XXVII";
    int number = romanToInt(s);
    cout << "Equivalent integer: " << number << endl;
    
    return 0;
}
