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
    Node* inorderpredecessor(Node* root){
        Node* pre = root->left;
        while(pre->right) pre = pre->right;
        return pre;
    }
    Node* delNode(Node* root, int x) {
        if(!root) return NULL;
        if(root->data == x){
            if(!root->left and !root->right) return NULL;
            else if(!root->left or !root->right){
                if(!root->left) return root->right;
                else return root->left;
            } else{
                Node* pre = inorderpredecessor(root);
                root->data = pre->data;
                root->left = delNode(root->left, pre->data);
            }
        } else if(root->data > x){
            root->left = delNode(root->left, x);
        } else root->right = delNode(root->right, x);
        return root;
    }
};

int main() {

    return 0;
}