#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(const string& a, const string& b) {
        if (a.length() != b.length()) return false;

        vector<int> count(26);
        for (char c : a) ++count[c - 'a'];
        for (char c : b) --count[c - 'a'];

        for (int c : count) if(c != 0) return false;
        return true;
    }
    
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;

        for (int i = 0; i < words.size();) {
            int j = i + 1;
            while (j < words.size() && isAnagram(words[i], words[j])) ++j;
            result.push_back(words[i]);
            i = j;
        }

        return result;
    }
};




int main() {

    return 0;
}