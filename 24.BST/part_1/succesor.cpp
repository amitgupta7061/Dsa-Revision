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
    int inOrderSuccessor(Node *root, Node *x) {
        int result = -1;
        while(root){
            if(x->data >= root->data) root = root->right;
            else{
                result = root->data;
                root = root->left;
            }
        }
        return result;
    }
};

class Solution {
public:
    int inOrderPredeccessor(Node *root, Node *x) {
        int result = -1;
        while(root){
            if(x->data <= root->data) root = root->left;
            else{
                result = root->data;
                root = root->right;
            }
        }
        return result;
    }
};



int main() {

    return 0;
}