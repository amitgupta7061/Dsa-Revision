#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};


class Solution {
public:
    Node *treeFromString(string str) {
        if(!str.size()) return NULL;
        stack<Node*> st;
        Node* root = NULL;

        for(int i = 0; i < str.size();){
            if(str[i] == ')'){
                st.pop(); i++;
            } else if(str[i] == '('){
                if (i + 1 < str.size() && str[i + 1] == ')') {
                    if(!st.top()->left) st.top()->left = NULL;
                    else st.top()->right = NULL;
                    i += 2;
                } else {
                    i++;
                }
            }
            else {
                bool neg = false;
                if(str[i] == '-'){
                    neg = true; i++;
                }
                int num = 0;
                while(i < str.size() and isdigit(str[i])){
                    num = num * 10 + (str[i] - '0');
                    i++;
                }
                if(neg) num = -num;

                Node* node = new Node(num);

                if(!st.empty()){
                    if(!st.top()->left) st.top()->left = node;
                    else st.top()->right = node;
                } else {
                    root = node;
                }
                st.push(node);
            }
        }
        return root;
    }
};


class Solution {
public:
    Node* solve(string &s, int &i) {
        if (i >= s.size()) return NULL;
        bool neg = false;
        if (s[i] == '-') {
            neg = true;
            i++;
        }

        int num = 0;
        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        if (neg) num = -num;
        Node* root = new Node(num);

        // Left subtree
        if (i < s.size() && s[i] == '(') {
            i++; // skip '('
            if (s[i] != ')') root->left = solve(s, i);
            i++; // skip ')'
        }

        // Right subtree
        if (i < s.size() && s[i] == '(') {
            i++; // skip '('
            if (s[i] != ')') root->right = solve(s, i);
            i++; // skip ')'    
        }

        return root;
    }

    Node* treeFromString(string str) {
        int i = 0;
        return solve(str, i);
    }
};


int main() {

    return 0;
}