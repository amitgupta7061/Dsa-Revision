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
        while(root){
            if(p->val < root->val and q->val < root->val) root = root->left;
            else if(p->val > root->val and q->val > root->val) root = root->right;
            else return root;
        }
        return NULL;
    }
};

int main() {

    return 0;
}