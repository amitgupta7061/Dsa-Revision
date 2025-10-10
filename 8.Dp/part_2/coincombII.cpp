#include <bits/stdc++.h>
using namespace std;


int main() {

    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    vector<int> coins(n);
    for (auto &el : coins) cin >> el;

    return 0;
}