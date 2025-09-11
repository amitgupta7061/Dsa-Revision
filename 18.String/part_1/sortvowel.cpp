#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        int prev = -1;
        unordered_set<char> vowel = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        string v = "";
        for(int i = 0; i < s.length(); i++){
            if(vowel.count(s[i])){
                v += s[i];
                s[i] = '#';
            }
        }
        if(!v.size()) return s;
        sort(v.begin(), v.end());
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#'){
                s[i] = v[j++];
            }
        }
        return s;
    }
};

int main() {

    return 0;
}