#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int src, unordered_map<int, vector<int>> &adj, unordered_set<int> &vis, unordered_set<int> &knows) {
        vis.insert(src);
        knows.insert(src);
        for (int neigh : adj[src]) {
            if (!vis.count(neigh)) f(neigh, adj, vis, knows);
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b) { return a[2] < b[2]; });

        unordered_set<int> knows;
        knows.insert(0);
        knows.insert(firstPerson);

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            unordered_map<int, vector<int>> adj;

            int j = i;
            while (j < meetings.size() && meetings[j][2] == time) {
                adj[meetings[j][0]].push_back(meetings[j][1]);
                adj[meetings[j][1]].push_back(meetings[j][0]);
                j++;
            }

            unordered_set<int> vis;
            for (auto &[p, _] : adj) {
                if (knows.count(p) && !vis.count(p)) {
                    f(p, adj, vis, knows);
                }
            }

            i = j;
        }

        return vector<int>(knows.begin(), knows.end());
    }
};


int main() {

    return 0;
}