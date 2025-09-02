#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int cnt = 0;
        for(auto &it : points){
            if(it[0] != it[1]) cnt++;
        }
        return cnt;
    }
};

int main() {

    return 0;
}