#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin >> n;

    long long sum = 0, actualsum = ((long long)n * ((long long)n + 1)) / 2LL;
    int num;

    n--;
    while(n--){
        cin>>num;
        sum += num;
    }

    cout<<actualsum - sum;

    return 0;
}