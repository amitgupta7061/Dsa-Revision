#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> sieveEratosthenes(int n) {
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i < n; ++i){
            if (isPrime[i]){
                for (int j = i * i; j < n; j += i) isPrime[j] = false;
            }
        }
        return isPrime;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        vector<bool> isPrime = sieveEratosthenes(101);
        int mini = -1, maxi = -1;

        for (int i = 0; i < nums.size(); ++i){
            if (isPrime[nums[i]]) {
                if (mini == -1) mini = i;
                maxi = i;
            }
        }
        
        return maxi - mini;
    }
};

int main() {

    return 0;
}