#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> memo;
    void buildnextlevel(string &base, int ind, string &curr, unordered_map<string, vector<char>> &mp, vector<string> &nextlevel) {
        if (ind == base.size() - 1) {
            nextlevel.push_back(curr); return;
        }

        string key;
        key += base[ind];
        key += base[ind + 1];

        if (!mp.count(key)) return;

        for (char ch : mp[key]) {
            curr.push_back(ch);
            buildnextlevel(base, ind + 1, curr, mp, nextlevel);
            curr.pop_back();
        }
    }

    bool f(string base, unordered_map<string, vector<char>> &mp) {
        if (base.size() == 1) return true;
        if (memo.count(base)) return memo[base];

        vector<string> nextlevel;
        string curr = "";
        buildnextlevel(base, 0, curr, mp, nextlevel);

        for (auto &it : nextlevel) {
            if (f(it, mp)) return memo[base] = true;
        }
        return memo[base] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return f(bottom, mp);
    }
};


int main() {

    return 0;
}