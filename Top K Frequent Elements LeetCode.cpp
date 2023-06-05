#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap;
    
    for (int num : nums) {
        frequencyMap[num]++;
    }
    
    auto compare = [](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
    
    for (auto& entry : frequencyMap) {
        pq.push(entry);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        pq.pop();
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> topKFrequentElements = topKFrequent(nums, k);
    
    cout << "The " << k << " most frequent elements are: ";
    for (int num : topKFrequentElements) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
