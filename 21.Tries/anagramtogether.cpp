#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> mp;
        for(string &word : arr){
            string temp = word;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(word);
        }
        vector<vector<string>> result;
        for(auto [x, y] : mp){
            result.push_back(y);
        }
        return result;
    }
};

class Solution {
public:
    class Node {
    public:
        Node* child[26];
        vector<int> idx;   // store indices of original words

        Node() {
            for(int i = 0; i < 26; i++) child[i] = NULL;
        }
    };

    void insert(Node* root, string &key, int index) {
        Node* curr = root;
        for(char ch : key) {
            int c = ch - 'a';
            if(!curr->child[c]) {
                curr->child[c] = new Node();
            }
            curr = curr->child[c];
        }
        curr->idx.push_back(index);
    }

    void dfs(Node* root, vector<string> &arr, vector<vector<string>> &ans) {
        if(!root) return;

        if(!root->idx.empty()) {
            vector<string> group;
            for(int i : root->idx) {
                group.push_back(arr[i]);
            }
            ans.push_back(group);
        }

        for(int i = 0; i < 26; i++) {
            dfs(root->child[i], arr, ans);
        }
    }

    vector<vector<string>> anagrams(vector<string>& arr) {
        Node* root = new Node();

        for(int i = 0; i < arr.size(); i++) {
            string key = arr[i];
            sort(key.begin(), key.end());   // canonical form
            insert(root, key, i);
        }

        vector<vector<string>> ans;
        dfs(root, arr, ans);
        return ans;
    }
};


int main() {

    return 0;
}