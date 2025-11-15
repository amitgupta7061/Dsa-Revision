#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, long> map;
        map[0] = 1;

        int currxor = 0;
        long result = 0;

        for(int num : arr){
            currxor ^= num;
            result += map[currxor ^ k];
            map[currxor]++;
        }
        return result;
    }
};

int main() {

    return 0;
}