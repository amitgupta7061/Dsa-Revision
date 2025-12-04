#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> f(string &exp, int st, int en){
        vector<int> result;
        if(st == en){
            result.push_back(exp[st] - '0'); return result;
        }
        else if(en - st == 1 and isdigit(exp[st])){
            result.push_back(stoi(exp.substr(st, en+1))); return result;
        }
        for(int i = st; i <= en; i++){
            if(isdigit(exp[i])) continue;
            vector<int> left = f(exp, st, i-1);
            vector<int> rght = f(exp, i+1, en);
            for(int l : left){
                for(int r : rght){
                    if(exp[i] == '+') result.push_back(l + r);
                    else if(exp[i] == '-') result.push_back(l - r);
                    else result.push_back(l * r);
                }
            }
        }
        return result;
    }
    vector<int> diffWaysToCompute(string expression) {
        return f(expression, 0, expression.size()-1);
    }
};

int main() {

    return 0;
}