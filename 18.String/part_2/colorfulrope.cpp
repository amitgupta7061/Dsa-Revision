#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int result = 0, n = colors.size(), i = 0;

        while (i < n) {
            char curr = colors[i];
            int sum = 0, maxi = 0;

            while (i < n && colors[i] == curr) {
                sum += neededTime[i];
                maxi = max(maxi, neededTime[i]);
                i++;
            }

            result += sum - maxi;
        }

        return result;
    }
};


int main() {

    return 0;
}