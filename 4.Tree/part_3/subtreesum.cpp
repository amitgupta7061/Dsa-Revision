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
    int f(TreeNode* root, unordered_map<int, int> &map, int &maxfreq){
        if(!root) return 0;
        int left = root->left ? f(root->left, map, maxfreq) : 0;
        int rght = root->right ? f(root->right, map, maxfreq) : 0;
        int totalsum = left + rght + root->val;
        map[totalsum]++;
        maxfreq = max(maxfreq, map[totalsum]);
        return totalsum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> map;
        int maxfreq = -1;
        f(root, map, maxfreq);

        vector<int> result;
        for(auto &it : map){
            if(it.second == maxfreq) result.push_back(it.first);
        }
        return result;
    }
};

int main() {

    return 0;
}