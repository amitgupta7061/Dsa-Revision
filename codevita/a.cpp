#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<string>& shuffled, vector<string>& original) {
    int n = shuffled.size();
    
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (shuffled[i] == original[j]) {
                pos[i] = j;
                break;
            }
        }
    }
    
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        vector<int> dp(n, 1);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < j; k++) {
                if (pos[k] < pos[j]) {
                    dp[j] = max(dp[j], dp[k] + 1);
                }
            }
            maxLen = max(maxLen, dp[j]);
        }
    }
    
    maxLen = 1;
    for (int i = 0; i < n; i++) {
        int len = 1;
        int lastPos = pos[i];
        for (int j = i + 1; j < n; j++) {
            if (pos[j] > lastPos) {
                len++;
                lastPos = pos[j];
            }
        }
        maxLen = max(maxLen, len);
    }
    
    return n - maxLen;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    string line;
    getline(cin, line); // "shuffled"
    
    vector<string> shuffled(n);
    for (int i = 0; i < n; i++) {
        getline(cin, shuffled[i]);
    }
    
    getline(cin, line); // "original"
    
    vector<string> original(n);
    for (int i = 0; i < n; i++) {
        getline(cin, original[i]);
    }
    
    cout << minOperations(shuffled, original) << endl;
    
    return 0;
}