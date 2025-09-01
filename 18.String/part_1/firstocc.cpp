#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(n > m) return -1;
        for(int i = 0; i < m; i++){
            string temp = haystack.substr(i, n);
            if(temp == needle) return i;
        }
        return -1;
    }
};

int main() {

    return 0;
}