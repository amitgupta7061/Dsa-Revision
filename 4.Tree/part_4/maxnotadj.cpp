#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    pair<int,int> dfs(Node* root) {
        if (!root) return {0, 0};
        auto L = dfs(root->left);
        auto R = dfs(root->right);
        int include = root->data + L.second + R.second;
        int exclude = max(L.first, L.second) + max(R.first, R.second);
        return {include, exclude};
    }

    int getMaxSum(Node *root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};


int main() {

    return 0;
}