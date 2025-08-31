#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string f(string &s){
        string newStr = "";
        int i = 0;
        while(i < s.length()){
            char ch = s[i];
            int cnt = 0;
            while(i < s.length() and s[i] == ch){
                cnt++; i++;
            }
            newStr += to_string(cnt);
            newStr += ch;
        }
        return newStr;
    }
    string countAndSay(int n) {
        string result = "1";
        for(int i = 2; i <= n; i++){
            result = f(result);
        }
        return result;
    }
};

int main() {

    return 0;
}