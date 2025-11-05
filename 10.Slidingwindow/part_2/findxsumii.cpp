#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        set<pair<int, int>> topX, remaining;
        long long currentSum = 0;
        unordered_map<int, int> frequency;
      
        auto addToSets = [&](int value) {
            if (frequency[value] == 0) return;
          
            pair<int, int> element = {frequency[value], value};
            if (!topX.empty() && element > *topX.begin()) {
                currentSum += 1LL * element.first * element.second; 
                topX.insert(element);
            } else {
                remaining.insert(element);
            }
        };
    
        auto removeFromSets = [&](int value) {
            if (frequency[value] == 0) return; 
            pair<int, int> element = {frequency[value], value};
          
            auto it = topX.find(element);
            if (it != topX.end()) {
                currentSum -= 1LL * element.first * element.second; // frequency * value
                topX.erase(it);
            } else {
                remaining.erase(element);
            }
        };
      
        vector<long long> result;
        for (int i = 0; i < nums.size(); ++i) {
            removeFromSets(nums[i]);
            ++frequency[nums[i]];
            addToSets(nums[i]);
        
            int windowStart = i - k + 1;
            if (windowStart < 0) continue;
            while (!remaining.empty() && topX.size() < x) {
                pair<int, int> best = *remaining.rbegin();
                currentSum += 1LL * best.first * best.second;
                remaining.erase(best);
                topX.insert(best);
            }
          
            while (topX.size() > x) {
                pair<int, int> worst = *topX.begin(); // Get worst from topX
                currentSum -= 1LL * worst.first * worst.second;
                topX.erase(worst);
                remaining.insert(worst);
            }
          
            result.push_back(currentSum);
            removeFromSets(nums[windowStart]);
            --frequency[nums[windowStart]];
            addToSets(nums[windowStart]);
        }
      
        return result;
    }
};

int main() {

    return 0;
}