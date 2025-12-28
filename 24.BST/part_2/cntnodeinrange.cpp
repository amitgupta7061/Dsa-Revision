#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int getCount(Node *root, int l, int h) {
        if (!root) return 0;
        if (root->data < l) return getCount(root->right, l, h);
        if (root->data > h) return getCount(root->left, l, h);
        return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
    }
};


int main() {

    return 0;
}