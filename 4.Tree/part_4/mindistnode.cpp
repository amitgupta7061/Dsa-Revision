#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    Node* lca(Node* root, int a, int b) {
        if (!root) return NULL;
        if (root->data == a || root->data == b) return root;

        Node* left = lca(root->left, a, b);
        Node* right = lca(root->right, a, b);

        if (left && right) return root;
        return left ? left : right;
    }
    int distanceFrom(Node* root, int target) {
        if (!root) return -1;
        if (root->data == target) return 0;

        int left = distanceFrom(root->left, target);
        if (left != -1) return left + 1;

        int right = distanceFrom(root->right, target);
        if (right != -1) return right + 1;

        return -1;
    }

    int findDist(Node* root, int a, int b) {
        Node* LCA = lca(root, a, b);
        int d1 = distanceFrom(LCA, a);
        int d2 = distanceFrom(LCA, b);
        return d1 + d2;
    }
};


int main() {

    return 0;
}