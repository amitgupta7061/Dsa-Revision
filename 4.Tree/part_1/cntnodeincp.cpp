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
    int getHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        
        if (leftH == rightH) { // left is perfect bt
            return (1 << leftH) + countNodes(root->right);
        } else {  // rght is perfect bt
            return (1 << rightH) + countNodes(root->left);
        }
    }
};


int main() {

    return 0;
}