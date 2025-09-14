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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr) {
            if (curr->left == NULL) {
                // No left child → visit directly
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;

                // Find inorder predecessor
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // Make thread and go left (do NOT visit yet)
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // Thread exists → break it and visit
                    prev->right = NULL;
                    result.push_back(curr->val);
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