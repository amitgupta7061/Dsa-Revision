#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list(wordList.begin(), wordList.end());
        queue<pair<string, int>> q; 
        q.push({beginWord, 1});
        if(list.find(beginWord) != list.end()) list.erase(beginWord);

        while(q.size()){
            auto [word, steps] = q.front(); q.pop();
            if(word == endWord) return steps;
            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(list.count(word)){
                        list.erase(word); q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

int main() {

    return 0;
}