#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class Node{
    public:
        int cnt;
        Node* child[26];
        Node(){
            cnt = 0;
            for(int i = 0; i < 26; i++) child[i] = NULL;
        }
    };
    void insertinTries(Node* root, string word){
        Node* curr = root;
        for(char ch : word){
            int ind = ch - 'a';
            if(!curr->child[ind]){
                curr->child[ind] = new Node();
            }
            curr = curr->child[ind];
            curr->cnt += 1;
        }
    }
    string GetPrefix(string word, Node* root){
        Node* curr = root;
        string result = "";
        for(char ch : word){
            int ind = ch - 'a';
            result += ch;
            curr = curr->child[ind];
            if(curr->cnt == 1) break;
        }
        return result;
    }
    vector<string> findPrefixes(string arr[], int n) {
        Node* root = new Node();
        for(int i = 0; i < n; i++){
            insertinTries(root, arr[i]);
        }
        vector<string> result(n);
        for(int i = 0; i < n; i++){
            result[i] = GetPrefix(arr[i], root);
        }
        return result;
    }
};


int main() {

    return 0;
}