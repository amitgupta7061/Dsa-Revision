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
    long long MOD = 1000000007LL;

    long long getsum(TreeNode* root){
        if(!root) return 0;
        return (long long)root->val + getsum(root->left) + getsum(root->right);
    }

    long long f(TreeNode* root, long long &maxi, const long long totalsum){
        if(!root) return 0;
        long long l = f(root->left, maxi, totalsum);
        long long r = f(root->right, maxi, totalsum);
        long long sumofsubtree = l + r + (long long)root->val;
        long long restsum = totalsum - sumofsubtree;
        maxi = max(maxi, sumofsubtree * restsum);
        return sumofsubtree;
    }
    int maxProduct(TreeNode* root) {
        long long totalsum = getsum(root);
        long long maxi = 0;
        f(root, maxi, totalsum);
        return (int)(maxi % MOD);
    }
};

int main() {

    return 0;
}