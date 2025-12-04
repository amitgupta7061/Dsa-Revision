#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    void f(vector<int> &cand, int k, int ind, vector<int> &temp, vector<vector<int>> &result){
        if(k == 0){
            result.push_back(temp); return;
        }
        for(int i = ind; i < cand.size(); i++){
            if(i > ind and cand[i] == cand[i-1]) continue;

            if(cand[i] > k) break;

            temp.push_back(cand[i]);
            f(cand, k-cand[i], i+1, temp, result);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        f(candidates, target, 0, temp, result);
        return result;
    }
};

int main() {

    return 0;
}