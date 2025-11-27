#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
        
        vector<int> a(n);
        vector<int> positions; // positions with known values (not -1)
        vector<int> minus1_pos; // positions with -1
        map<int, int> cnt; // count of each value
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == -1) {
                minus1_pos.push_back(i);
            } else {
                positions.push_back(i);
                cnt[a[i]]++;
            }
        }
        
        // Greedy: place all X first, then others
        // Build the arrangement
        vector<int> values;
        int x_count = cnt[x];
        for (int i = 0; i < x_count; i++) values.push_back(x);
        for (auto& [v, c] : cnt) {
            if (v != x) {
                for (int i = 0; i < c; i++) values. push_back(v);
            }
        }
        
        // Assign values to positions (sorted)
        sort(positions.begin(), positions. end());
        vector<int> arr(n, -1);
        for (int i = 0; i < (int)positions.size(); i++) {
            arr[positions[i]] = values[i];
        }
        
        // Simulate voting
        map<int, int> freq;
        map<int, int> votes;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                freq[arr[i]]++;
                votes[arr[i]]++;
            } else {
                // Find unique max frequency value
                int max_freq = 0;
                for (auto& [v, f] : freq) max_freq = max(max_freq, f);
                
                int max_count = 0;
                int max_val = -1;
                for (auto& [v, f] : freq) {
                    if (f == max_freq) {
                        max_count++;
                        max_val = v;
                    }
                }
                
                if (max_count == 1 && max_val != -1) {
                    votes[max_val]++;
                }
                // else: person doesn't vote
            }
        }
        
        // Check if X wins uniquely
        int x_votes = votes[x];
        bool wins = true;
        if (x_votes == 0) wins = false;
        for (auto& [v, vt] : votes) {
            if (v != x && vt >= x_votes) {
                wins = false;
                break;
            }
        }
        
        cout << (wins ? "Yes" : "No") << "\n";
    }
    
    return 0;
}