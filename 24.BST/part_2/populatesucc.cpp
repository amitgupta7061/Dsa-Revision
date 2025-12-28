#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};


class Solution {
  public:
    void populateNext(Node *root) {
        Node* curr = root;
        Node* prev = NULL;

        while (curr) {
            if (!curr->left) {
                if (prev) prev->next = curr;
                prev = curr;
                curr = curr->right;
            } else {
                Node* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    if (prev) prev->next = curr;
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
    }
};


int main() {

    return 0;
}