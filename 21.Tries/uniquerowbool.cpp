#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col) {
        set<vector<int>> seen;
        vector<vector<int>> ans;

        for (int i = 0; i < row; i++) {
            vector<int> curr;
            for (int j = 0; j < col; j++) {
                curr.push_back(M[i][j]);
            }

            if (seen.find(curr) == seen.end()) {
                seen.insert(curr);
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

class Solution {
public:
    struct TrieNode {
        TrieNode* child[2];
        bool isEnd;
        TrieNode() {
            child[0] = child[1] = nullptr;
            isEnd = false;
        }
    };

    bool insert(TrieNode* root, int rowArr[], int col) {
        TrieNode* node = root;
        for (int i = 0; i < col; i++) {
            int bit = rowArr[i];
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
        if (node->isEnd) return false; // already exists
        node->isEnd = true;
        return true;
    }

    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col) {
        TrieNode* root = new TrieNode();
        vector<vector<int>> ans;

        for (int i = 0; i < row; i++) {
            if (insert(root, M[i], col)) {
                vector<int> temp;
                for (int j = 0; j < col; j++)
                    temp.push_back(M[i][j]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};



int main() {

    return 0;
}