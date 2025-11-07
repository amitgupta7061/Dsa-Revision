#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Maximum number of nodes and logN for LCA
const int MAXN = 100005;
const int LOGN = 18; // ceil(log2(100005))

// --- LCA (Least Common Ancestor) and Tree Structure ---

vector<int> adj[MAXN];
int depth[MAXN];
int parent[MAXN][LOGN];
int N, M;

// DFS for LCA preprocessing
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

// Function to find the LCA of two nodes u and v
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    // Lift u up
    for (int i = LOGN - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = parent[u][i];
        }
    }

    if (u == v) return u;

    // Lift both u and v up simultaneously
    for (int i = LOGN - 1; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

// --- Persistent Segment Tree (PST) ---

struct Node {
    int count; // Frequency count in the range
    int left, right; // Indices of left and right children in the tree_nodes array
};

Node tree_nodes[MAXN * LOGN * 2]; // Max nodes: N * (logN updates) * 2 for children
int node_count = 0;
int Root[MAXN]; // Root[i] stores the root of the PST for the path from root to node i
int W_ranks[MAXN]; // Discretized weight rank for each node

// Function to update the PST (increment count at a specific index)
int update_pst(int prev_node_idx, int l, int r, int target_idx) {
    int new_node_idx = ++node_count;
    tree_nodes[new_node_idx] = tree_nodes[prev_node_idx]; // Copy old node

    tree_nodes[new_node_idx].count++; // Increment count

    if (l == r) {
        return new_node_idx;
    }

    int mid = l + (r - l) / 2;
    if (target_idx <= mid) {
        // Only the left child is modified, copy the right child
        tree_nodes[new_node_idx].left = update_pst(tree_nodes[prev_node_idx].left, l, mid, target_idx);
    } else {
        // Only the right child is modified, copy the left child
        tree_nodes[new_node_idx].right = update_pst(tree_nodes[prev_node_idx].right, mid + 1, r, target_idx);
    }

    return new_node_idx;
}

// DFS to build the PST for all nodes
void build_pst(int u, int p) {
    // Root[u] is built by persisting Root[p] and updating with u's weight rank
    Root[u] = update_pst(Root[p], 1, N, W_ranks[u]);

    for (int v : adj[u]) {
        if (v != p) {
            build_pst(v, u);
        }
    }
}

// Function to query the kth minimum element on the path P(u,v)
int query_kth(int R1, int R2, int R3, int R4, int l, int r, int k, const vector<int>& weights) {
    if (l == r) {
        return weights[l - 1]; // Found the rank, return the original weight
    }

    int mid = l + (r - l) / 2;

    // Calculate the total frequency count in the LEFT child range
    // P(u,v) = P(root, u) + P(root, v) - P(root, lca) - P(root, parent(lca))
    int count_left = tree_nodes[tree_nodes[R1].left].count + 
                     tree_nodes[tree_nodes[R2].left].count -
                     tree_nodes[tree_nodes[R3].left].count -
                     tree_nodes[tree_nodes[R4].left].count;

    if (k <= count_left) {
        // kth element is in the left sub-range [l, mid]
        return query_kth(tree_nodes[R1].left, tree_nodes[R2].left, 
                         tree_nodes[R3].left, tree_nodes[R4].left,
                         l, mid, k, weights);
    } else {
        // kth element is in the right sub-range [mid+1, r]
        // Adjust k and recurse on the right children
        return query_kth(tree_nodes[R1].right, tree_nodes[R2].right, 
                         tree_nodes[R3].right, tree_nodes[R4].right,
                         mid + 1, r, k - count_left, weights);
    }
}

// --- Main Logic ---

void solve() {
    cin >> N >> M;

    vector<int> weights_orig(N + 1);
    vector<int> weights_unique;

    for (int i = 1; i <= N; ++i) {
        cin >> weights_orig[i];
        weights_unique.push_back(weights_orig[i]);
    }

    // 1. Discretization
    sort(weights_unique.begin(), weights_unique.end());
    weights_unique.erase(unique(weights_unique.begin(), weights_unique.end()), weights_unique.end());

    for (int i = 1; i <= N; ++i) {
        // Replace weight with its 1-based rank (index + 1)
        W_ranks[i] = lower_bound(weights_unique.begin(), weights_unique.end(), weights_orig[i]) - weights_unique.begin() + 1;
    }
    
    // N will now represent the size of the rank array (W' in the explanation)
    // The segment tree will operate on the range [1, weights_unique.size()]
    int W_prime = weights_unique.size(); 

    // 2. Read Edges and Build Adjacency List
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 3. Preprocessing
    // Initialize parent[0][0] to 0, which acts as the 'null' node for the root
    dfs_lca(1, 0, 1); 
    
    // Root[0] is an empty PST for the parent of the root (node 1)
    Root[0] = 0; 
    build_pst(1, 0); 
    
    // 4. Process Queries
    for (int i = 0; i < M; ++i) {
        int u, v, k;
        cin >> u >> v >> k;

        int l = lca(u, v);
        int p = parent[l][0]; // parent of LCA

        // The query uses the segment tree roots: Root[u], Root[v], Root[l], Root[p]
        // The segment tree operates on the range [1, W_prime]
        int result = query_kth(Root[u], Root[v], Root[l], Root[p], 
                               1, W_prime, k, weights_unique);
        
        cout << result << "\n";
    }
}

int main() {
    // Fast I/O is often necessary for competitive programming problems
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
