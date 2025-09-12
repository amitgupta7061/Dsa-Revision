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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> map;
        queue<tuple<int, int, TreeNode*>> q;
        q.push({0, 0, root});

        while(q.size()){
            auto [x, y, node] = q.front(); q.pop();
            map[x][y].insert(node->val);

            if(node->left) q.push({x-1, y+1, node->left});
            if(node->right) q.push({x+1, y+1, node->right});
        }

        vector<vector<int>> result;
        for(auto &col : map){
            vector<int> temp;
            for(auto &row : col.second){
                temp.insert(temp.end(), row.second.begin(), row.second.end());
            }
            result.push_back(temp);
        }

        return result;
    }
};

int main() {

    return 0;
}