#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerString(const string &s) {
        string res = s;
        for (char &c : res) c = tolower(c);
        return res;
    }

    string devowel(const string &s) {
        string res = s;
        for (char &c : res) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
                c = '*';
            }
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;  
        unordered_map<string, string> vowelInsensitive;

        for (auto &word : wordlist) {
            string lower = toLowerString(word);
            if (!caseInsensitive.count(lower)) caseInsensitive[lower] = word;

            string vlow = devowel(lower);
            if (!vowelInsensitive.count(vlow)) vowelInsensitive[vlow] = word;
        }

        vector<string> result;
        for (auto &q : queries) {
            if (exact.count(q)) {
                result.push_back(q);
            } else {
                string lower = toLowerString(q);
                if (caseInsensitive.count(lower)) {
                    result.push_back(caseInsensitive[lower]);
                } else {
                    string vlow = devowel(lower);
                    if (vowelInsensitive.count(vlow)) {
                        result.push_back(vowelInsensitive[vlow]);
                    } else {
                        result.push_back("");
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    
}
