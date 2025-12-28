#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public: 
    bool isDeadEnd(Node *root, int mini = 1, int maxi = INT_MAX) {
        if(!root) return false;
        if(!root->left and !root->right){
            return mini == maxi;
        }
        return isDeadEnd(root->left, mini, root->data-1) or isDeadEnd(root->right, root->data+1, maxi);
    }
};

int main() {

    return 0;
}