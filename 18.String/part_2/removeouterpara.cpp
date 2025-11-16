#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string> decom;
        int cnt = 0;
        string temp = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') cnt++;
            else cnt--;
            temp += s[i];

            if(cnt == 0){
                decom.push_back(temp);
                temp = "";
            }
        }
        string result = "";
        for(auto str : decom){
            str.pop_back();
            result += str.substr(1);
        }
        return result;
    }
};

int main() {

    return 0;
}