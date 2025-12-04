#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insertatBottom(stack<int> &st, int peek){
        if(st.empty()){
            st.push(peek); return;
        }
        int curr = st.top(); st.pop();
        insertatBottom(st, peek);
        st.push(curr);
    }
    void reverseStack(stack<int> &st) {
        if(st.empty()) return;
        int peek = st.top(); st.pop();
        reverseStack(st);
        insertatBottom(st, peek);
    }
};

int main() {

    return 0;
}