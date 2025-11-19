#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &prices, vector<int> &pages, int ind, int k, vector<vector<int>> &dp){
    if(k <= 0) return 0;
    if(ind >= prices.size()) return 0;

    if(dp[ind][k] != -1) return dp[ind][k];

    int take = 0;
    if(k >= prices[ind]){
        take = pages[ind] + f(prices, pages, ind+1, k-prices[ind], dp);
    }
    int notTake = f(prices, pages, ind+1, k, dp);
    
    return dp[ind][k] =  max(take, notTake);
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> prices(n), pages(n);
    for(auto &price : prices) cin >> price;
    for(auto &page : pages) cin >> page;



    vector<vector<int>> dp(n, vector<int>(k, -1));

    cout<< f(prices, pages, 0, k, dp);


    

    return 0;
}