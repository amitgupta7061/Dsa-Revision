#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 100005;
const int LOGN = 18; // ceil(log2(100005))


vector<int> adj[MAXN];
int depth[MAXN];
int parent[MAXN][LOGN];
int N, M;

void dfs_lca(int u, int p, int d) {
    depth[u] = d;
    parent[u][0] = p;

    for (int i = 1; i < LOGN; ++i) {
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }

    for (int v : adj[u]) {
        if (v != p) {
            dfs_lca(v, u, d + 1);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = LOGN - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = parent[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOGN - 1; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}


struct Node {
    int count; // Frequency count in the range
    int left, right; // Indices of left and right children in the tree_nodes array
};

Node tree_nodes[MAXN * LOGN * 2]; // Max nodes: N * (logN updates) * 2 for children
int node_count = 0;
int Root[MAXN]; // Root[i] stores the root of the PST for the path from root to node i
int W_ranks[MAXN]; // Discretized weight rank for each node

int update_pst(int prev_node_idx, int l, int r, int target_idx) {
    int new_node_idx = ++node_count;
    tree_nodes[new_node_idx] = tree_nodes[prev_node_idx]; // Copy old node

    tree_nodes[new_node_idx].count++; // Increment count

    if (l == r) {
        return new_node_idx;
    }

    int mid = l + (r - l) / 2;
    if (target_idx <= mid) {
        tree_nodes[new_node_idx].left = update_pst(tree_nodes[prev_node_idx].left, l, mid, target_idx);
    } else {
        tree_nodes[new_node_idx].right = update_pst(tree_nodes[prev_node_idx].right, mid + 1, r, target_idx);
    }

    return new_node_idx;
}

void build_pst(int u, int p) {
    Root[u] = update_pst(Root[p], 1, N, W_ranks[u]);

    for (int v : adj[u]) {
        if (v != p) {
            build_pst(v, u);
        }
    }
}

int query_kth(int R1, int R2, int R3, int R4, int l, int r, int k, const vector<int>& weights) {
    if (l == r) {
        return weights[l - 1]; // Found the rank, return the original weight
    }

    int mid = l + (r - l) / 2;

    int count_left = tree_nodes[tree_nodes[R1].left].count + 
                     tree_nodes[tree_nodes[R2].left].count -
                     tree_nodes[tree_nodes[R3].left].count -
                     tree_nodes[tree_nodes[R4].left].count;

    if (k <= count_left) {
        return query_kth(tree_nodes[R1].left, tree_nodes[R2].left, 
                         tree_nodes[R3].left, tree_nodes[R4].left,
                         l, mid, k, weights);
    } else {
        return query_kth(tree_nodes[R1].right, tree_nodes[R2].right, 
                         tree_nodes[R3].right, tree_nodes[R4].right,
                         mid + 1, r, k - count_left, weights);
    }
}


void solve() {
    cin >> N >> M;

    vector<int> weights_orig(N + 1);
    vector<int> weights_unique;

    for (int i = 1; i <= N; ++i) {
        cin >> weights_orig[i];
        weights_unique.push_back(weights_orig[i]);
    }

    sort(weights_unique.begin(), weights_unique.end());
    weights_unique.erase(unique(weights_unique.begin(), weights_unique.end()), weights_unique.end());

    for (int i = 1; i <= N; ++i) {
        W_ranks[i] = lower_bound(weights_unique.begin(), weights_unique.end(), weights_orig[i]) - weights_unique.begin() + 1;
    }
    
    int W_prime = weights_unique.size(); 

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_lca(1, 0, 1); 
    
    Root[0] = 0; 
    build_pst(1, 0); 
    
    for (int i = 0; i < M; ++i) {
        int u, v, k;
        cin >> u >> v >> k;

        int l = lca(u, v);
        int p = parent[l][0]; // parent of LCA

        int result = query_kth(Root[u], Root[v], Root[l], Root[p], 
                               1, W_prime, k, weights_unique);
        
        cout << result << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
