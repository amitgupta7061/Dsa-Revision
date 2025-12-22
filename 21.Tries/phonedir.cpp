#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            for (int i = 0; i < 26; i++) child[i] = nullptr;
            isEnd = false;
        }
    };

    TrieNode* root;
    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    void dfs(TrieNode* node, string &prefix, vector<string> &res) {
        if (node->isEnd) res.push_back(prefix);

        for (int i = 0; i < 26; i++) {
            if (node->child[i]) {
                prefix.push_back('a' + i);
                dfs(node->child[i], prefix, res);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        root = new TrieNode();

        for (int i = 0; i < n; i++) insert(contact[i]);

        vector<vector<string>> ans;
        TrieNode* node = root;
        string prefix = "";

        for (char c : s) {
            prefix.push_back(c);
            int idx = c - 'a';

            if (!node || !node->child[idx]) {
                ans.push_back({"0"});
                node = nullptr;
                continue;
            }

            node = node->child[idx];
            vector<string> temp;
            string curr = prefix;
            dfs(node, curr, temp);

            if (temp.empty()) ans.push_back({"0"});
            else ans.push_back(temp);
        }

        return ans;
    }
};


int main() {

    return 0;
}