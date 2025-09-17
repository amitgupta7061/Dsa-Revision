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
    int findBottomLeftValue(TreeNode* root) {
        int answerlevel = -1, answer = -1;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while(q.size()){
            auto [node, currlevel] = q.front(); q.pop();

            if(currlevel != answerlevel){
                answerlevel = currlevel;
                answer = node->val;
            }

            if(node->left) q.push({node->left, currlevel+1});
            if(node->right) q.push({node->right, currlevel+1});
        }

        return answer;
    }
};

int main() {

    return 0;
}