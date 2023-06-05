#include <iostream>
#include <unordered_map>

using namespace std;

int balancedString(string s) {
    int n = s.length();
    int target_count = n / 4;
    unordered_map<char, int> frequency_map;
    
    for (char ch : s) {
        frequency_map[ch]++;
    }
    
    int left = 0;
    int min_length = INT_MAX;
    
    for (int right = 0; right < n; right++) {
        frequency_map[s[right]]--;
        
        while (left < n && frequency_map['Q'] <= target_count && frequency_map['W'] <= target_count &&
               frequency_map['E'] <= target_count && frequency_map['R'] <= target_count) {
            min_length = min(min_length, right - left + 1);
            frequency_map[s[left]]++;
            left++;
        }
    }
    
    return min_length;
}

int main() {
    string s = "QQWE";
    int min_length = balancedString(s);
    cout << "Minimum length of substring to replace: " << min_length << endl;
    
    return 0;
}
