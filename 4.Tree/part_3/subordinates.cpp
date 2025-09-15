#include <bits/stdc++.h>
using namespace std;

int f(int src, vector<vector<int>> &tree, vector<int> &dp){
    int cnt = 0;
    for(auto &neigh : tree[src]){
        cnt += (1 + f(neigh, tree, dp));
    }
    return dp[src] = cnt;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> tree(n+1);
    for(int i = 2; i <= n; i++){
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    vector<int> dp(n+1, 0);
    f(1, tree, dp);

    for(int i = 1; i <= n; i++) cout<<dp[i]<<" ";

    return 0;
}