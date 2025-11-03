#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result = INT_MAX;
    void solve(int ind, vector<int>& cookies, vector<int>& children, int k) {
        if(ind == cookies.size()) {
            int ans = *max_element(begin(children), end(children));
            result = min(result, ans);
            return;
        }
        
        for(int i = 0; i < k; i++) {
            children[i] += cookies[ind];
            solve(ind+1, cookies, children, k);
            children[i] -= cookies[ind];
        }   
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k);
        solve(0, cookies, children, k);
        return result;
    }
};

int main() {

    return 0;
}