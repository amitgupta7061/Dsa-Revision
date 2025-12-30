#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};

class Solution {
public:
    void f(Node* root, Node*& prev) {
        if (!root) return;
        f(root->left, prev);
        prev->right = root;
        root->left = prev;
        prev = root;
        f(root->right, prev);
    }

    Node* bToDLL(Node* root) {
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        f(root, prev);
        Node* head = dummy->right;
        if (head) head->left = NULL;
        return head;
    }
};


int main() {

    return 0;
}