#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        int cntofseat = count(corridor.begin(), corridor.end(), 'S');
        if (cntofseat == 0 || cntofseat % 2) return 0;

        long long result = 1;
        int i = 0, currseat = 0;

        while (i < corridor.size()) {
            if (currseat < 2) {
                if (corridor[i] == 'S') {
                    currseat++; cntofseat--;
                }
                i++;
            } 
            else {
                if (cntofseat == 0) break;
                int spacecnt = 1;
                while (i < corridor.size() && corridor[i] != 'S') {
                    spacecnt++; i++;
                }
                result = (result * spacecnt) % MOD;
                currseat = 0;
            }
        }

        return result;
    }
};


int main() {

    return 0;
}