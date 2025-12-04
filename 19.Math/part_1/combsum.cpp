#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    void f(vector<int> &cand, int k, int ind, vector<int> &temp, vector<vector<int>> &result){
        if(ind == cand.size()){
            if(k == 0) result.push_back(temp); return;
        }
        if(k < 0) return;
        if(k == 0){
            result.push_back(temp); return;
        }
        // take
        temp.push_back(cand[ind]);
        f(cand, k-cand[ind], ind, temp, result);
        temp.pop_back();

        // not take
        f(cand, k, ind+1, temp, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        f(candidates, target, 0, temp, result);
        return result;
    }
};

int main() {

    return 0;
}