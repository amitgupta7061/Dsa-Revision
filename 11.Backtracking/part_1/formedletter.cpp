#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> lettersCounter;
        for (char letter : letters) lettersCounter[letter]++;

        int totalScore = 0;

        function<void(int, unordered_map<char, int>, int)> explore =
            [&](int ind, unordered_map<char, int> letterCounter, int currScore) {
                totalScore = max(totalScore, currScore);
                if (ind == words.size()) return;

                for (int i = ind; i < words.size(); ++i) {
                    unordered_map<char, int> tmpCounter = letterCounter;
                    string word = words[i];
                    int wordScore = 0;
                    bool isValid = true;

                    for (char ch : word) {
                        if (tmpCounter[ch] > 0) {
                            tmpCounter[ch]--;
                            wordScore += score[ch - 'a'];
                        } else {
                            isValid = false;
                            break;
                        }
                    }

                    if (isValid) {
                        explore(i + 1, tmpCounter, currScore + wordScore);
                    }
                }
            };

        explore(0, lettersCounter, 0);
        return totalScore;
    }
};

int main() {

    return 0;
}