#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(2 * n), first(n + 1), second(n + 1);
        
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            if (first[a[i]] == 0) {
                first[a[i]] = i + 1;
            } else {
                second[a[i]] = i + 1;
            }
        }
        
        deque<int> window;
        set<int> inWindow;
        int cnt = 0;
        
        for (int i = 0; i < 2 * n; i++) {
            int val = a[i];
            if (inWindow.find(val) == inWindow.end()) {
                cnt++;
                window.push_back(val);
                inWindow.insert(val);
                if ((int)window.size() >= n) {
                    int old = window.front();
                    window. pop_front();
                    inWindow. erase(old);
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}