#include <bits/stdc++.h>
using namespace std;

int f(int start, vector<vector<int>> &graph, vector<bool> &white, int n) {
    if (white[start]) return 0;
    queue<pair<int, int>> q;
    vector<bool> visited(n + 1, false);
    q.push({start, 0});
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front().first, dist = q.front().second; q.pop();
        
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                if (white[v]) return dist + 1;
                q.push({v, dist + 1});
            }
        }
    }
    return -1;
}

int main() {
    
    int n, q;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> white(n + 1, false);
    cin >> q;
    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        
        if (temp == 0) {
            int node;
            cin >> node;
            white[node] = !white[node];
        } else {
            int v;
            cin >> v;
            cout << f(v, graph, white, n) << "\n";
        }
    }
    return 0;
}
