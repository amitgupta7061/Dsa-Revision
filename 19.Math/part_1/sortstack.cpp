#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insertinStack(stack<int> &st, int peek){
        if(st.empty() or st.top() <= peek){
            st.push(peek); return;
        }
        int topE = st.top(); st.pop();
        insertinStack(st, peek);
        st.push(topE);
    }
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        int peek = st.top(); st.pop();
        sortStack(st);
        insertinStack(st, peek);
    }
};

int main() {

    return 0;
}