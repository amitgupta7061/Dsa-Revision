#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calSteps(int n, long n1, long n2){
        int step = 0;
        while(n1 <= n){
            step += min((long)n+1,n2) - n1;
            n1 *= 10, n2 *= 10;
        }
        return step;
    }
    int findKthNumber(int n, int k) {
        int curr = 1; k -= 1;
        while(k > 0){
            int step = calSteps(n, curr, curr + 1);
            if(step <= k){
                curr += 1;
                k -= step;
            } else{
                curr *= 10; k -= 1;
            }
        }
        return curr;
    }
};


int main() {

    return 0;
}