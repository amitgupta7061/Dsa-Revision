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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val == p->val or root->val == q->val) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* rght = lowestCommonAncestor(root->right, p, q);

        if(!left) return rght;
        else if(!rght) return left;
        else return root;
    }
};


int main() {

    return 0;
}