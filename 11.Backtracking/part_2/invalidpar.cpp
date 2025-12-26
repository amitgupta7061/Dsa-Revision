#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        int opened = 0;
        for (char ch : s) {
            if (ch == '(') opened++;
            else if (ch == ')') opened--;
            if (opened < 0) return false;
        }
        return true;
    }

    pair<int, int> getLeftAndRightCounts(const string& s) {
        int l = 0, r = 0;

        for (char ch : s){
            if (ch == '(') l++;
            else if (ch == ')') l == 0 ? r++ : l--;
        }   

        return {l, r};
    }

    void dfs(const string& s, int start, int l, int r, vector<string>& result) {
        if (l == 0 && r == 0 && isValid(s)) {
            result.push_back(s); return;
        }

        for (int i = start; i < s.length(); ++i) {
            if (i > start && s[i] == s[i - 1]) continue;
            if (l > 0 && s[i] == '(')
                dfs(s.substr(0, i) + s.substr(i + 1), i, l - 1, r, result);
            if (r > 0 && s[i] == ')')
                dfs(s.substr(0, i) + s.substr(i + 1), i, l, r - 1, result);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        auto [l, r] = getLeftAndRightCounts(s);
        dfs(s, 0, l, r, result);
        return result;
    }
};


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        int leftcnt = 0, rghtcnt = 0, n = s.size();
    
        for (char& ch : s) {
            if (ch == '(') {
                leftcnt++;
            } else if (ch == ')') {
                if (leftcnt > 0) {
                    leftcnt--;
                } else {
                    rghtcnt++;
                }
            }
        }

        function<void(int, int, int, int, int, string)> dfs = [&](int ind, int leftRem, int rightRem, int leftCount, int rightCount, string current) {
            if (ind == n) {
                if (leftRem == 0 && rightRem == 0) {
                    result.insert(current);
                }
                return;
            }
            if (n - ind < leftRem + rightRem || leftCount < rightCount) {
                return;
            }
            if (s[ind] == '(' && leftRem > 0) {
                dfs(ind + 1, leftRem - 1, rightRem, leftCount, rightCount, current);
            }
            if (s[ind] == ')' && rightRem > 0) {
                dfs(ind + 1, leftRem, rightRem - 1, leftCount, rightCount, current);
            }
            int addLeft = (s[ind] == '(') ? 1 : 0;
            int addRight = (s[ind] == ')') ? 1 : 0;
            dfs(ind + 1, leftRem, rightRem, leftCount + addLeft, rightCount + addRight, current + s[ind]);
        };
        dfs(0, leftcnt, rghtcnt, 0, 0, "");
        return vector<string>(result.begin(), result.end());
    }
};

int main() {

    return 0;
}