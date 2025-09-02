#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases;
    cin >> testcases;

    while(testcases--){
        long long y, x;
        cin >> y >> x;

        long long result;
        if(y > x){
            if(y % 2) result = (y-1) * (y-1) + x;
            else result = y * y - x + 1;
        } else {
            if(x % 2) result = x * x - y + 1;
            else result = (x-1) * (x-1) + y;
        }

        cout<<result<<"\n";
    }

    return 0;
}