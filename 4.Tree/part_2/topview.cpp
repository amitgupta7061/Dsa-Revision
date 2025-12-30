#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void f(Node* root, int ind, map<int, int> &mp){
        if(!root) return;
        f(root->left, ind-1, mp);
        if(!mp.count(ind)) mp[ind] = root->data;
        f(root->right, ind+1, mp);
    }
    vector<int> topView(Node *root) {
        map<int, int> mp;
        f(root, 0, mp);
        vector<int> result;
        for(auto it : mp) result.push_back(it.second);
        return result;
    }
};

int main() {

    return 0;
}