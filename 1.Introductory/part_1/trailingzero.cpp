#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin >> n;

    int cnt = 0;

    while(n != 0){
        cnt += (n / 5);
        n /= 5;
    }

    cout<<cnt;

    return 0;
}