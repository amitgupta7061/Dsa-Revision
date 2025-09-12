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
    int isSumProperty(TreeNode *root) {
        if(!root) return true;
        if(!root->left and !root->right) return true;
        
        int sum = 0;
        if(root->left) sum += root->left->val;
        if(root->right) sum += root->right->val;

        if(sum != root->val) return false;
        return isSumProperty(root->left) and isSumProperty(root->right);
    }
};


int main() {

    return 0;
}