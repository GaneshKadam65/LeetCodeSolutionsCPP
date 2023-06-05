#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    
    string prefix = strs[0];
    int n = strs.size();
    
    for (int i = 1; i < n; i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            
            if (prefix.empty()) {
                return "";
            }
        }
    }
    
    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    string commonPrefix = longestCommonPrefix(strs);
    cout << "Longest common prefix: " << commonPrefix << endl;
    
    return 0;
}
