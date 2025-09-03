#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        if(i == 1) cout<<"0\n";
        else {
            long long total = 1LL * i * i * (1LL * i * i - 1) / 2;
            long long attacking = 4LL * (i - 1) * (i - 2);
            cout << total - attacking << "\n";

        }
    }

    return 0;
}