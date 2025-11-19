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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr) {
            if (curr->left == NULL) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;

                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    result.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};




int main() {

    return 0;
}