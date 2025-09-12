#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        string result = "";
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            TreeNode* node = q.front(); q.pop();
            if(node) result += (to_string(node->val) + ',');
            else result += "#,";

            if(node) q.push(node->left);
            if(node) q.push(node->right);
        }

        return result;
    }
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            TreeNode* node = q.front(); q.pop();
            
            getline(ss, val, ',');
            if(val == "#") node->left = NULL;
            else {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }

            getline(ss, val, ',');
            if(val == "#") node->right = NULL;
            else {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }

        }
        return root;
    }
};

int main() {

    return 0;
}