#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        for (auto &p : adjacentPairs) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        int start = 0;
        for (auto &[num, neighbors] : graph) {
            if (neighbors.size() == 1) {
                start = num;
                break;
            }
        }

        int n = adjacentPairs.size() + 1;
        vector<int> result;
        unordered_set<int> visited;

        function<void(int)> dfs = [&](int node) {
            result.push_back(node);
            visited.insert(node);

            for (int nei : graph[node]) {
                if (!visited.count(nei))
                    dfs(nei);
            }
        };

        dfs(start);
        return result;
    }
};

int main() {

    return 0;
}