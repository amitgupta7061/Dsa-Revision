#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].length();
        vector<int> lis(n+1, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                bool flag = true;
                for(auto &s : strs){
                    if(s[j] > s[i]){
                        flag = false; break;
                    }
                }
                if(flag) lis[i] = max(lis[i], lis[j]+1);
            }
        }
        int maxi = 0;
        for (int x : lis) maxi = max(maxi, x);

        return n - maxi;
    }
};

int main() {

    return 0;
}