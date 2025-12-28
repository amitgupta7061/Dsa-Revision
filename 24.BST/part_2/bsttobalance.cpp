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
    Node* buildBST(vector<Node*> &nums, int l, int r){
        if (l > r) return NULL;
        int mid = (l + r) / 2;
        Node* root = nums[mid];
        root->left = buildBST(nums, l, mid-1);
        root->right = buildBST(nums, mid+1, r);
        return root;
    }
    Node* balanceBST(Node* root) {
        vector<Node*> nums;
        Node *curr = root;
        while(curr){
            if(!curr->left){
                nums.push_back(curr);
                curr = curr->right;
            } else{
                Node* pred = curr->left;
                while(pred->right and pred->right != curr) pred = pred->right;

                if(pred->right){
                    pred->right = NULL;
                    nums.push_back(curr);
                    curr = curr->right;
                } else{
                    pred->right = curr;
                    curr = curr->left;
                }
            }
        }
        return buildBST(nums, 0, nums.size()-1);
    }
};

int main() {

    return 0;
}