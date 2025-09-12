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
    TreeNode* f(vector<int> &post, vector<int> &in, int st, int ed, int &ind){
        if(st > ed) return NULL;
        TreeNode* root = new TreeNode(post[ind]);
        int i;
        for(i = st; i <= ed; i++) if(post[ind] == in[i]) break;
        ind--;

        root->right = f(post, in, i+1, ed, ind);
        root->left = f(post, in, st, i-1, ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size(), ind = n - 1;
        return f(postorder, inorder, 0, n - 1, ind);
    }
};

int main() {

    return 0;
}