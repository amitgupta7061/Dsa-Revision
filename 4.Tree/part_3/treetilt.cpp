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
    int f(TreeNode* root, int &sum){
        if(!root) return 0;
        int left = f(root->left, sum);
        int rght = f(root->right, sum);
        sum += abs(left - rght);
        return left + rght + root->val;
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        f(root, sum);
        return sum;
    }
};

int main() {

    return 0;
}