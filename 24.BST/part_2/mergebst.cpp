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
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;
        Node *cur1 = root1, *cur2 = root2;

        auto nextInorder = [](Node* &cur) -> Node* {
            while (cur) {
                if (!cur->left) {
                    Node* res = cur;
                    cur = cur->right;
                    return res;
                } else {
                    Node* pred = cur->left;
                    while (pred->right && pred->right != cur)
                        pred = pred->right;

                    if (!pred->right) {
                        pred->right = cur;
                        cur = cur->left;
                    } else {
                        pred->right = NULL;
                        Node* res = cur;
                        cur = cur->right;
                        return res;
                    }
                }
            }
            return NULL;
        };

        Node *n1 = nextInorder(cur1);
        Node *n2 = nextInorder(cur2);

        while (n1 && n2) {
            if (n1->data <= n2->data) {
                ans.push_back(n1->data);
                n1 = nextInorder(cur1);
            } else {
                ans.push_back(n2->data);
                n2 = nextInorder(cur2);
            }
        }

        while (n1) {
            ans.push_back(n1->data);
            n1 = nextInorder(cur1);
        }

        while (n2) {
            ans.push_back(n2->data);
            n2 = nextInorder(cur2);
        }

        return ans;
    }
};


int main() {

    return 0;
}