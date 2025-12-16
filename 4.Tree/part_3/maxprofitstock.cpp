#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(int u, vector<int>& present, vector<int>& future, unordered_map<int, vector<int>>& adj,vector<vector<vector<int>>>& statesProfit, int budget) {
        vector<pair<vector<int>, vector<int>>> childrenStatesProfit;
        for (int v : adj[u]) {
            DFS(v, present, future, adj, statesProfit, budget);
            childrenStatesProfit.push_back({statesProfit[v][0], statesProfit[v][1]});
        }

        for (int parentBought = 0; parentBought <= 1; ++parentBought) {

            int price  = (parentBought == 1) ? present[u] / 2 : present[u];
            int profit = future[u] - price;
            
            vector<int> bestProfitAtU(budget + 1, 0);
            vector<int> childrenProfitIfUNotBought(budget + 1, 0);

            for (auto& child : childrenStatesProfit) {
                vector<int> temp(budget + 1, 0);

                for (int used = 0; used <= budget; ++used) { 
                    for (int take = 0; used + take <= budget; ++take) { 
                        temp[used + take] = max(temp[used + take], childrenProfitIfUNotBought[used] + child.first[take]);
                    }
                }
                childrenProfitIfUNotBought = move(temp);
            }

            for (int b = 0; b <= budget; ++b) {
                bestProfitAtU[b] = max(bestProfitAtU[b], childrenProfitIfUNotBought[b]);
            }
            if (price <= budget) {
                vector<int> childrenProfitIfUBought(budget + 1, 0);

                for (auto& child : childrenStatesProfit) {
                    vector<int> temp(budget + 1, 0);

                    for (int used = 0; used <= budget; ++used) {
                        for (int take = 0; used + take <= budget; ++take) {
                            temp[used + take] = max(temp[used + take], childrenProfitIfUBought[used] + child.second[take]);
                        }
                    }
                    childrenProfitIfUBought = move(temp);
                }

                for (int b = price; b <= budget; ++b) {
                    bestProfitAtU[b] = max(bestProfitAtU[b], childrenProfitIfUBought[b - price] + profit);
                }
            }

            statesProfit[u][parentBought] = move(bestProfitAtU);
        }
    }

    int maxProfit( int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        unordered_map<int, vector<int>> adj;
        for (auto& it : hierarchy) {
            int boss = it[0]-1, emp = it[1]-1;
            adj[boss].push_back(emp);
        }
        vector<vector<vector<int>>> statesProfit(n, vector<vector<int>>(2, vector<int>(budget + 1, 0)));
        DFS(0, present, future, adj, statesProfit, budget);

        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            ans = max(ans, statesProfit[0][0][b]);
        }
        return ans;
    }
};

int main() {

    return 0;
}