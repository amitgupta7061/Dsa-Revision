#include <bits/stdc++.h>
using namespace std;

bool canwecut(vector<int> &tree, int k, int mid){
    int sum = 0;
    for(auto it : tree){
        if(it < mid) continue;
        sum += it - mid;
        if(sum > k) return false;
    }
    return sum == k;
}

int f(vector<int> &tree, int k){
    int low = *min_element(tree.begin(), tree.end());
    int high = *max_element(tree.begin(), tree.end());

    bool flag;
    int ans = -1;

    while(low < high){
        int mid = low + (high - low) / 2;
        if(canwecut(tree, k, mid)){
            ans = mid;
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> tree(n);
    for(auto &it : tree) cin >> it;

    cout<<f(tree, k);

    return 0;
}
