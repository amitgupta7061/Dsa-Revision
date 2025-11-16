#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> freq;
        int l = 0, r = 0, maxi = -1, n = s.length();

        while(r < n){
            freq[s[r]]++;

            while(freq.size() > k){
                freq[s[l]] == 1 ? freq.erase(s[l]) : freq[s[l]]--;
                l++;
            }
            if(freq.size() == k) maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};

int main() {

    return 0;
}