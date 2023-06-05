#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    stack<char> brackets;
    unordered_map<char, char> closingBracketMap = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            brackets.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (brackets.empty() || brackets.top() != closingBracketMap[ch]) {
                return false;
            }
            brackets.pop();
        }
    }
    
    return brackets.empty();
}

int main() {
    string s = "({[]})";
    bool valid = isValid(s);
    if (valid) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }
    
    return 0;
}
