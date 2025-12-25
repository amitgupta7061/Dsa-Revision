#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int round = 0, sum = 0;
        priority_queue<int> pq(happiness.begin(), happiness.end());

        while(pq.size()){
            int curr = pq.top() - round; pq.pop();
            sum += (curr < 0 ? 0 : curr);
            round++;
            if(--k == 0) return sum;
        }
        return -1;
    }
};

int main() {

    return 0;
}