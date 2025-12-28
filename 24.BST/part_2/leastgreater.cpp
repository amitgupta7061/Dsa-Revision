#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n);
        set<int> st;   // acts like BST

        for (int i = n - 1; i >= 0; i--) {
            auto it = st.upper_bound(arr[i]); // least greater
            if (it == st.end())
                ans[i] = -1;
            else
                ans[i] = *it;

            st.insert(arr[i]);
        }
        return ans;
    }
};


int main() {

    return 0;
}