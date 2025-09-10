#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2; // number of couples
        vector<vector<int>> graph(n);

        for (int i = 0; i < row.size(); i += 2) {
            int a = row[i] / 2, b = row[i+1] / 2;
            if (a != b) {
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int size = 0;
                stack<int> st;
                st.push(i);
                visited[i] = true;
                while (!st.empty()) {
                    int u = st.top(); st.pop();
                    size++;
                    for (int v : graph[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            st.push(v);
                        }
                    }
                }
                swaps += size - 1;
            }
        }

        return swaps;
    }
};


int main() {

    return 0;
}