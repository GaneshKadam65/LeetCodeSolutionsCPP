#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int maxVowels(string s, int k) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int maxCount = 0;
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        if (i >= k && vowels.count(s[i - k])) {
            count--;
        }

        if (vowels.count(s[i])) {
            count++;
        }

        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main() {
    string s = "leetcode";
    int k = 3;

    int result = maxVowels(s, k);

    cout << "Maximum number of vowels: " << result << endl;

    return 0;
}
