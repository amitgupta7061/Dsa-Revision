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
        if(!root->left and !root->right){
            int temp = root->data;
            root->data = 0;
            return temp;
        }
        int l = f(root->left);
        int r = f(root->right);
        int temp = root->data;
        root->data = l + r;
        return temp + l + r;
    }
    void toSumTree(Node *node) {
        f(node);
    }
};

int main() {

    return 0;
}