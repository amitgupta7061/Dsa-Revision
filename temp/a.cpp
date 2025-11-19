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

// Input:
// n = 5, k = 4
// tree[] = {2, 3, 6, 2, 4}
// Output: 3
// Explanation: Wood collected by cutting trees
// at height 3 = 0 + 0 + (6-3) + 0 + (4-3) = 4
// hence 3 is to be subtracted from all numbers.
// Since 2 is lesser than 3, nothing gets
// subtracted from it.