#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<string> arr(n);
        for(auto &it : arr) cin >> it;
        
        string res = "";
        
        for (int i = 0; i < n; i++) {
            string start = arr[i] + res, end = res + arr[i];
            
            if (start < end) res = start;
            else res = end;
        }
        
        cout << res << "\n";
    }
    
    return 0;
}