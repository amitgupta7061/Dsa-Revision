#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(string &s, int ind, string temp, unordered_set<string> &dict, vector<string> &result){
        if(ind == s.length()){
            temp.pop_back();
            result.push_back(temp);
            return;
        }
        for(int i = 1; i + ind <= s.length(); i++){
            string sub = s.substr(ind, i);
            if(dict.count(sub)){
                f(s, ind+i, temp+sub+" ", dict, result);
            }
        }
    }
    vector<string> wordBreak(vector<string>& dict, string& s) {
        unordered_set<string> dictionary(dict.begin(), dict.end());
        vector<string> result;
        f(s, 0, "", dictionary, result);
        return result;
    }
};

int main() {

    return 0;
}