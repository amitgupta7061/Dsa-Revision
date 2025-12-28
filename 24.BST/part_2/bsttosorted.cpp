#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    Node* flattenBST(Node* root) {
        Node* curr = root, *prev = NULL, *head = NULL;
        while (curr) {
            if (!curr->left) {
                if (!head) head = curr;
                if (prev) prev->right = curr;

                curr->left = NULL;
                prev = curr;
                curr = curr->right;
            } else {
                Node* pre = curr->left;
                while (pre->right && pre->right != curr) pre = pre->right;

                if (!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = NULL;

                    // visit curr
                    if (!head) head = curr;
                    if (prev) prev->right = curr;

                    curr->left = NULL;
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        return head;
    }
};


int main() {

    return 0;
}