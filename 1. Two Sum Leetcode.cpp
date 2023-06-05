#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        if (numMap.find(complement) != numMap.end()) {
            result.push_back(numMap[complement]);
            result.push_back(i);
            break;
        }
        
        numMap[nums[i]] = i;
    }
    
    return result;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> indices = twoSum(nums, target);
    if (indices.size() == 2) {
        cout << "Indices of the two numbers: " << indices[0] << ", " << indices[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }
    
    return 0;
}
