#include <bits/stdc++.h>
using namespace std;


int main() {

    string s;
    cin >> s;

    int maxlen = 1, cnt = 1;

    for(int i = 1; i < s.length(); i++){
        if(s[i] == s[i-1]) cnt++;
        else {
            maxlen = max(maxlen, cnt);
            cnt = 1;
        }
    }
    maxlen = max(maxlen, cnt);

    cout<<maxlen;
    return 0;
}