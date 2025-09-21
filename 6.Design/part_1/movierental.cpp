#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
public:
    unordered_map<long long, int> Shop;   // key(shop,movie) -> price
    unordered_map<int, set<pair<int, int>>> Movie;    // movie->set(price,shop)
    set<tuple<int, int, int>> rented;                 // rented->set (price,shop,movie)

    long long key(int shop, int movie) {
        return ((long long)shop << 32) | (long long)movie;
    }


    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop=e[0], movie=e[1], price=e[2];
            Shop[key(shop,movie)]=price;
            Movie[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        auto& S=Movie[movie];
        int i=0;
        for (auto it=S.begin(); it!=S.end() && i<5; it++, i++) {
            ans.push_back(it->second); // shop
        }
        return ans;
    }

    void rent(int shop,int movie) {
        int price=Shop[key(shop,movie)];
        Movie[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop,int movie) {
        int price=Shop[key(shop,movie)];
        Movie[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int i=0;
        for (auto it=rented.begin(); it!=rented.end() && i<5; it++, i++) {
            auto [price, shop, movie]=*it;
            ans.push_back({shop, movie});
        }
        return ans;
    }
};


int main() {

    return 0;
}