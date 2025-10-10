#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(), maxEnergy = INT_MIN;
        
        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n) {
                energy[i] += energy[i + k];
            }
            maxEnergy = max(maxEnergy, energy[i]);
        }
        
        return maxEnergy;
    }
};

int main() {

    return 0;
}