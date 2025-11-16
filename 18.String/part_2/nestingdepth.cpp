#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, maxi = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') cnt--;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};

int main() {

    return 0;
}