#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--){
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> temp(n);
        for(auto &it : temp) cin >> it;

        long long cnt = 0; 
        int l = 0;

        for(int r = 0; r < n; ){
            while(r < n && temp[r] <= q) r++;

            int len = r - l;

            if(len >= k){
                long long m = len - k + 1;
                cnt += m * (m + 1) / 2;
            }
            l = r + 1;
            r = l;
        }

        cout << cnt << "\n";
    }

    return 0;
}
