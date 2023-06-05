#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numSet;
    
    for (int num : nums) {
        if (numSet.count(num) > 0) {
            return true;  // Found a duplicate
        }
        numSet.insert(num);
    }
    
    return false;  // No duplicates found
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 2};
    bool hasDuplicates = containsDuplicate(nums);
    
    if (hasDuplicates) {
        cout << "The array contains duplicates." << endl;
    } else {
        cout << "The array does not contain duplicates." << endl;
    }
    
    return 0;
}
