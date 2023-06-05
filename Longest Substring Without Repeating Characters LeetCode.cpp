#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> charSet;
    int n = s.length();
    int maxLength = 0;
    int left = 0, right = 0;
    
    while (right < n) {
        if (charSet.find(s[right]) == charSet.end()) {
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
            right++;
        } else {
            charSet.erase(s[left]);
            left++;
        }
    }
    
    return maxLength;
}

int main() {
    string s = "abcabcbb";
    int length = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << length << endl;
    
    return 0;
}
