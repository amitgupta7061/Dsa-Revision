#include <bits/stdc++.h>
using namespace std;


int main() {

    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;

        bool a_win = false;

        if(a > b){
            a_win = true;
        } else if(a < b){
            a_win = false;
        } else{
            if(c % 2) a_win = true;
            else a_win = false;
        }

        if(a_win) cout<<"First\n";
        else cout<<"Second\n";
    }

    return 0;
}