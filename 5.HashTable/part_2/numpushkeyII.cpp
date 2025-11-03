#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for(char &ch : word) freq[ch]++;

        vector<int> counts;
        for(auto &p : freq) counts.push_back(p.second);
        sort(counts.rbegin(), counts.rend()); 

        int result = 0;
        for(int i = 0; i < counts.size(); i++){
            result += ((i / 8) + 1) * counts[i];
        }
        
        return result;
    }
};

int main() {

    return 0;
}