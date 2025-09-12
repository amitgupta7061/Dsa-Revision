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
    vector <int> bottomView(TreeNode *root) {
        map<int, int> map;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(q.size()){
            auto [node, level] = q.front(); q.pop();
            map[level] = node->val;

            if(node->left) q.push({node->left, level - 1});
            if(node->right) q.push({node->right, level + 1});
        }
        
        vector<int> result;
        for(auto it : map) result.push_back(it.second);

        return result;
    }
};

int main() {

    return 0;
}