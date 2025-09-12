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
    TreeNode* f(vector<int> &pre, vector<int> &in, int st, int ed, int &ind){
        if(st > ed) return NULL;
        TreeNode* root = new TreeNode(pre[ind]);
        int i;
        for(i = st; i <= ed; i++) if(in[i] == pre[ind]) break;
        ind++;
        root->left = f(pre, in, st, i - 1, ind);
        root->right = f(pre, in, i + 1, ed, ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind = 0, n = preorder.size();
        return f(preorder, inorder, 0, n - 1, ind);
    }
};

int main() {

    return 0;
}