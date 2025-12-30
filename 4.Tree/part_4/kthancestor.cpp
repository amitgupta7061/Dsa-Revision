#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    int ans = -1;
    int dfs(Node* root, int k, int node) {
        if (!root) return -1;
        if (root->data == node) return 0;

        int left = dfs(root->left, k, node);
        int right = dfs(root->right, k, node);

        int dist = -1;
        if (left != -1) dist = left + 1;
        else if (right != -1) dist = right + 1;

        if (dist == k) ans = root->data;

        return dist;
    }

    int kthAncestor(Node *root, int k, int node) {
        dfs(root, k, node);
        return ans;
    }
};


int main() {

    return 0;
}