#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, needopen = 0;
        for(auto &ch : s){
            if(ch == '(') cnt++;
            else cnt > 0 ? cnt-- : needopen++;
        }
        return cnt + needopen;
    }
};

int main() {

    return 0;
}