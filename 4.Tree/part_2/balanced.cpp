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
    int f(Node* root){
        if(!root) return 0;
        int l = f(root->left);
        int r = f(root->right);
        if(abs(l - r) > 1) return -1;
        return 1 + max(l, r);
    }
    bool isBalanced(Node* root) {
        return f(root) == -1 ? false : true;
    }
};

int main() {

    return 0;
}