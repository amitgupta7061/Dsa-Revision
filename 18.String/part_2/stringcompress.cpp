#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int ind = 0, n = chars.size();
      
        for (int curr = 0, next = curr + 1; curr < n;) {
            while (curr < n && chars[next] == chars[curr]) next++;
          
            chars[ind++] = chars[curr];
            int cnt = next - curr;
            if (cnt > 1) {
                string countStr = to_string(cnt);
                for (char digit : countStr) {
                    chars[ind++] = digit;
                }
            }
            curr = next;
        }
        
        return ind;
    }
};


int main() {

    return 0;
}