#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int inversionCount(vector<int> &nums) {
        stack<int> st;
        int cnt = 0, n = nums.size();
        st.push(nums.back());

        for(int i = -2; i >= 0; i--){
            while(st.size() and st.top() >= nums[i]) st.pop();
            cnt += st.size();
            st.push(nums[i]);
        }
        return cnt;
    }
};

int main() {

    return 0;
}