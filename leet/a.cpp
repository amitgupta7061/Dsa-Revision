class Solution {
public:
    long long minimumCost©leetcode(int cost1, int cost2, int costBoth, int need1, int need2) {
        auto calcCost = [&](long long k) -> long long {
            long long remaining1 = max(0LL, need1 - k);
            long long remaining2 = max(0LL, need2 - k);
            return k * costBoth + remaining1 * cost1 + remaining2 * cost2;
        };
        long long ans = calcCost(0);
        ans = min(ans, calcCost(min(need1, need2)));
        ans = min(ans, calcCost(max(need1, need2)));
        return ans;
    }
};
