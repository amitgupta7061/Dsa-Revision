#include <bits/stdc++.h>
using namespace std;

bool f(int n, bool vanyaT, int cnt){
    if(cnt > 10) return false;
    if(!vanyaT and n % 3 == 0) return true;

    if(vanyaT){
        return f(n-1, false, cnt+1) or f(n+1, false, cnt+1);
    } else {
        return f(n-1, true, cnt+1) and f(n+1, true, cnt+1);
    }
}

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(f(n, true, 0)) cout<<"First\n";
        else cout<<"Second\n";
    }

    return 0;
}