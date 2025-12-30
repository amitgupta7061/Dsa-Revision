#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* f(vector<int> &pre, vector<int> &in, int &ind, int l, int r){
        if(l > r) return NULL;
        TreeNode* root = new TreeNode(pre[ind]);
        int i;
        for(i = l; i <= r; i++) if(in[i] == pre[ind]) break;
        ind++;
        root->left = f(pre, in, ind, l, i-1);
        root->right = f(pre, in, ind, i+1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind = 0;
        return f(preorder, inorder, ind, 0, inorder.size()-1);
    }
};

int main() {

    return 0;
}