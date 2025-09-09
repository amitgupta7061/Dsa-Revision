#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> adj[26], indegree(26, 0), present(26, 0);
        for(string &word : words){
            for(char &ch : word) present[ch - 'a'] = 1;
        }

        for(int i = 0; i < words.size() - 1; i++){
            string word_1 = words[i], word_2 = words[i+1];
            int len = min(word_1.length(), word_2.length());
            bool found = false;

            for(int j = 0; j < len; j++){
                if(word_1[j] != word_2[j]){
                    adj[word_1[j] - 'a'].push_back(word_2[j] - 'a');
                    indegree[word_2[j] - 'a']++;
                    found = true;
                    break;
                }
            }

            if(!found and word_1.length() > word_2.length()) return "";
        }

        queue<int> q;
        for(int i = 0; i < 26; i++){
            if(present[i] and indegree[i] == 0) q.push(i);
        }

        string result = "";
        while(q.size()){
            int node = q.front(); q.pop();
            result.push_back(node + 'a');

            for(auto &neigh : adj[node]){
                if(--indegree[neigh] == 0) q.push(neigh);
            }
        }

        if(result.size() != count(present.begin(), present.end(), 1)) return "";
        return result;
    }
};


int main() {

    return 0;
}