#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    vector<Node*> child;
    bool terminal;
    Node(){
        child.resize(26, NULL);
        terminal = false;
    }
};

class Solution {
public:
    void insertInTrie(string &word, Node* root){
        Node* curr = root;
        for(char ch : word){
            int ind = ch - 'a';
            if(!curr->child[ind]){
                curr->child[ind] = new Node();
            }
            curr = curr->child[ind];
        }
        curr->terminal = true;
    }

    bool f(int ind, string &s, Node* root, vector<int> &dp){
        if(ind == s.size()) return true;
        if(dp[ind] != -1) return dp[ind];

        Node* curr = root;
        for(int i = ind; i < s.size(); i++){
            int ind = s[i] - 'a';
            if(!curr->child[ind]) break;
            curr = curr->child[ind];
            if(curr->terminal && f(i + 1, s, root, dp))
                return dp[ind] = true;
        }
        return dp[ind] = false;
    }

    int wordBreak(string target, vector<string> &list) {
        Node* root = new Node();
        for(string &word : list){
            insertInTrie(word, root);
        }
        vector<int> dp(target.size(), -1);
        return f(0, target, root, dp);
    }
};

class Solution {
public:
    int wordBreak(string s, vector<string> &dict) {
        unordered_set<string> st(dict.begin(), dict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && st.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};



int main() {

    return 0;
}