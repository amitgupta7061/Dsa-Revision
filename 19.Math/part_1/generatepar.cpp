#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int n, int cnt, string &temp, vector<string> &result){
        if(cnt < 0 or cnt > n) return;
        if(temp.size() == n*2){
            if(cnt == 0)result.push_back(temp); return;
        }
        temp.push_back('(');
        f(n, cnt+1, temp, result);
        temp.pop_back();
        temp.push_back(')');
        f(n, cnt-1, temp, result);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp;
        f(n, 0, temp, result);
        return result;
    }
};

int main() {

    return 0;
}