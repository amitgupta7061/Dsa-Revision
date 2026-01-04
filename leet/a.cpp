#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<long long> result(n, 0);
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] + diff[i - 1];
        }

        for (auto &it : restrictions) {
            result[it[0]] = min(result[it[0]], (long long)it[1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            result[i] = min(result[i], result[i + 1] + diff[i]);
        }

        for (int i = 1; i < n; i++) {
            result[i] = min(result[i], result[i - 1] + diff[i - 1]);
        }
        return *max_element(result.begin(), result.end());
    }
};


int main() {

    return 0;
}