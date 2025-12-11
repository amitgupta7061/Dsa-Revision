#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int cnt = 0, maxi = 0;
        for (int x : a) {
            if (x < maxi) cnt++;
            else maxi = x;
        }

        cout<<cnt<<endl;
    }
    return 0;
}