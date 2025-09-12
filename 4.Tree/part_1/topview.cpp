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

class Solution{
public:
    vector<int> topView(TreeNode* root){
        unordered_map<int, int> map;  // level, node
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0}); // node, level
        map[0] = root->val;

        while(q.size()){
            auto [node, level] = q.front(); q.pop();
            if(!map.count(level)) map[level] = node->val;
            
            if(node->left) q.push({node->left, level-1});
            if(node->right) q.push({node->right, level+1});
        }

        int minLevel = INT_MAX, maxLevel = INT_MIN;
        for(auto &it : map){
            minLevel = min(minLevel, it.first);
            maxLevel = max(maxLevel, it.first);
        }

        vector<int> result;
        for(int i = minLevel; i <= maxLevel; i++){
            result.push_back(map[i]);
        }

        return result;
    }
};


int main() {

    return 0;
}