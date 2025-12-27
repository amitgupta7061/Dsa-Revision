#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    void inorder(Node* root, vector<int>& values) {
        if (!root) return;
        inorder(root->left, values);
        values.push_back(root->data);
        inorder(root->right, values);
    }

    void replaceValues(Node* root, vector<int>& value, int& ind) {
        if (!root) return;
        replaceValues(root->left, value, ind);
        root->data = value[ind++];
        replaceValues(root->right, value, ind);
    }
    
    Node* binaryTreeToBST(Node* root) {
        if (!root) return nullptr;
        vector<int> values;
        inorder(root, values);
        sort(values.begin(), values.end());
        int ind = 0;
        replaceValues(root, values, ind);
        return root;
    }
};

int main() {

    return 0;
}