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
    string tree2str(TreeNode* root) {
        if(!root) return "";
        if(!root->left and !root->right){
            return to_string(root->val);
        }
        if(root->right == NULL){
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        }
        return to_string(root->val) + "(" + tree2str(root->left) + ")" +
                                      "(" + tree2str(root->right) + ")";
    }
};

int main() {

    return 0;
}