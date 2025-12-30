#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    int f(Node* root){
        if(!root) return 0;
        if(!root->left and !root->right) return root->data;
        int l = f(root->left);
        int r = f(root->right);
        if(l == -1 or r == -1) return -1; 
        if(l + r != root->data) return -1;
        return root->data + l + r;
    }
    bool isSumTree(Node* root) {
        return f(root) != -1;
    }
};

int main() {

    return 0;
}