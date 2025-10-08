#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int f(int spell, vector<int> &potions, long long success){
        int low = 0, n = potions.size(), high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long temp = potions[mid];
            if(temp*spell >= success) high = mid - 1;
            else low = mid + 1;
        }
        return n - high - 1;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result(spells.size());
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++){
            result[i] = f(spells[i], potions, success);
        }
        return result;
    }
};

int main() {

    return 0;
}
