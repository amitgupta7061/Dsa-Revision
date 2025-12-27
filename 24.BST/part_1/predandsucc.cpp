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
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pred = NULL;
        Node* succ = NULL;
        Node* curr = root;

        while (curr) {
            if (curr->data == key) {
                // predecessor
                if (curr->left) {
                    pred = curr->left;
                    while (pred->right) pred = pred->right;
                }
                // successor
                if (curr->right) {
                    succ = curr->right;
                    while (succ->left) succ = succ->left;
                }
                break;
            }
            else if (curr->data < key) {
                pred = curr;
                curr = curr->right;
            }
            else {
                succ = curr;
                curr = curr->left;
            }
        }
        return {pred, succ};
    }
};


int main() {

    return 0;
}