#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        stack<int> st;
        int root = INT_MIN;
        for(int i = 0; i < N; i++){
            while(st.size() > 0 and arr[i] > st.top()){
                root = st.top();
                st.pop();
            }
            if(arr[i] < root) return false;
            st.push(arr[i]);
        }
        return true;
    }
};

// 2 4 3

int main() {

    return 0;
}