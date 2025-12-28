#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    int findMedian(Node* root) {
        if (!root) return 0;
        int n = 0;
        Node* curr = root;

        while (curr) {
            if (!curr->left) {
                n++;
                curr = curr->right;
            } else {
                Node* pre = curr->left;
                while (pre->right && pre->right != curr) pre = pre->right;

                if (!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = NULL;
                    n++;
                    curr = curr->right;
                }
            }
        }

        int k = (n + 1) / 2, cnt = 0;
        curr = root;

        while (curr) {
            if (!curr->left) {
                cnt++;
                if (cnt == k) return curr->data;
                curr = curr->right;
            } else {
                Node* pre = curr->left;
                while (pre->right && pre->right != curr) pre = pre->right;

                if (!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = NULL;
                    cnt++;
                    if (cnt == k) return curr->data;
                    curr = curr->right;
                }
            }
        }

        return 0;
    }
};


int main() {

    return 0;
}