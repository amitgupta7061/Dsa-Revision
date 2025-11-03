#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int &num : arr) map[num]++;

        unordered_set<int> seen;
        for(auto &[num, cnt] : map){
            if(seen.count(cnt)) return false;
            seen.insert(cnt);
        }
        return true;
    }
};

int main() {

    return 0;
}