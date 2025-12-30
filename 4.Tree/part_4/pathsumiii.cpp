#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    void dfs(TreeNode* root, long long currSum, int target,
             unordered_map<long long, int>& mp, int &cnt) {

        if (!root) return;

        currSum += root->val;

        if (mp.count(currSum - target))
            cnt += mp[currSum - target];

        mp[currSum]++;

        dfs(root->left, currSum, target, mp, cnt);
        dfs(root->right, currSum, target, mp, cnt);

        mp[currSum]--; // backtrack
    }

    int countAllPaths(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0] = 1;   // base case

        int cnt = 0;
        dfs(root, 0, targetSum, mp, cnt);
        return cnt;
    }
};


int main() {

    return 0;
}