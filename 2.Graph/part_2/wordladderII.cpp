#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        
        if (wordSet.find(endWord) == wordSet.end()) {
            return result;
        }
        
        unordered_map<string, vector<string>> neighbors;
        unordered_map<string, int> distances;
        
        queue<string> q;
        q.push(beginWord);
        distances[beginWord] = 0;
        
        bool found = false;
        int level = 0;
        
        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> visited; // Words visited in current level
            
            for (int i = 0; i < size; i++) {
                string currentWord = q.front();
                q.pop();
                
                for (int j = 0; j < currentWord.length(); j++) {
                    char originalChar = currentWord[j];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        
                        string newWord = currentWord;
                        newWord[j] = c;
                        
                        if (wordSet.find(newWord) != wordSet.end()) {
                            if (newWord == endWord) {
                                found = true;
                            }
                            
                            if (distances.find(newWord) == distances.end()) {
                                distances[newWord] = level + 1;
                                visited.insert(newWord);
                                neighbors[newWord].push_back(currentWord);
                            }
                            else if (distances[newWord] == level + 1) {
                                neighbors[newWord].push_back(currentWord);
                            }
                        }
                    }
                }
            }
            
            for (const string& word : visited) {
                q.push(word);
            }
            level++;
        }
        
        if (!found) {
            return result;
        }
        
        vector<string> path = {endWord};
        dfs(endWord, beginWord, neighbors, path, result);
        
        return result;
    }
    
private:
    void dfs(string word, string beginWord, unordered_map<string, vector<string>>& neighbors,
             vector<string>& path, vector<vector<string>>& result) {
        
        if (word == beginWord) {
            vector<string> validPath(path.rbegin(), path.rend());
            result.push_back(validPath);
            return;
        }
        
        for (const string& neighbor : neighbors[word]) {
            path.push_back(neighbor);
            dfs(neighbor, beginWord, neighbors, path, result);
            path.pop_back();
        }
    }
};

int main() {

    return 0;
}