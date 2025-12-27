#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    bool isBST(Node* root, int mini = INT_MIN, int maxi = INT_MAX) {
        if(!root) return true;
        if(root->data <= mini or root->data >= maxi) return false;
        return isBST(root->left, mini, root->data) and isBST(root->right, root->data, maxi);
    }
};

int main() {

    return 0;
}