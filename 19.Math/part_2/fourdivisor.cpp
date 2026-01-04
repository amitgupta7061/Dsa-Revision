#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto &num : nums){
            int cnt = 0, divsum = 0;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    int d1 = i, d2 = num / i;
                    if (d1 == d2) {
                        cnt += 1; divsum += d1;
                    } else {
                        cnt += 2; divsum += d1 + d2;
                    }
                }
            }
            if(cnt == 4) sum += divsum;
        }
        return sum;
    }
};

int main() {

    return 0;
}