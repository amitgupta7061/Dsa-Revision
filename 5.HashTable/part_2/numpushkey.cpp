#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size(), result = 0;
        for(int i = 0; i < n; i++){
            result += (i / 8) + 1;
        }
        return result;
    }
};


int main() {

    return 0;
}