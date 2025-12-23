#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

// Helper to calculate ceil(k/2) correctly for negative numbers
ll ceil_div2(ll k) {
    if (k >= 0) return (k + 1) / 2;
    return k / 2;
}

// Helper to calculate floor(k/2) correctly for negative numbers
ll floor_div2(ll k) {
    if (k >= 0) return k / 2;
    return (k - 1) / 2;
}

void solve() {
    int n;
    ll x, y;
    if (!(cin >> n >> x >> y)) return;
    string s;
    cin >> s;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    ll LB_A = 0; // Lower Bound for A
    ll LB_B = 0; // Lower Bound for B
    ll G0 = 0;   // Population Gap for Type 0
    ll G1 = 0;   // Population Gap for Type 1
    ll Margin0 = 0; // Margin cap for Type 0
    ll Margin1 = 0; // Margin cap for Type 1
    
    bool has_0 = false;
    bool has_1 = false;

    for (int i = 0; i < n; ++i) {
        // Minimum winning votes required
        ll base_req = p[i] / 2 + 1; 
        // Max votes loser can have initially relative to winner (floor(p/2))
        ll margin = p[i] / 2;       
        // Population gap after allocating base_req to winner and 0 to loser
        ll gap = p[i] - base_req;
        
        if (s[i] == '0') {
            has_0 = true;
            LB_A += base_req;
            G0 += gap;
            Margin0 += margin;
        } else {
            has_1 = true;
            LB_B += base_req;
            G1 += gap;
            Margin1 += margin;
        }
    }

    // Basic feasibility check
    if (x < LB_A || y < LB_B) {
        cout << "NO" << endl;
        return;
    }

    // Excess votes available
    ll EA = x - LB_A;
    ll EB = y - LB_B;

    if (has_0 && !has_1) {
        // Case: All districts are Type 0 (A wins)
        // Must satisfy total population needs
        if (EA + EB < G0) {
            cout << "NO" << endl;
            return;
        }
        // Excess B must not overwhelm Excess A beyond the margin
        // Constraint: EB - EA <= Margin0
        if (EB - EA > Margin0) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
    } else if (!has_0 && has_1) {
        // Case: All districts are Type 1 (B wins)
        // Must satisfy total population needs
        if (EA + EB < G1) {
            cout << "NO" << endl;
            return;
        }
        // Excess A must not overwhelm Excess B beyond the margin
        // Constraint: EA - EB <= Margin1
        if (EA - EB > Margin1) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
    } else {
        // Case: Mixed district types
        // We define ranges for the sum (x+y) and diff (y-x) of allocations to Type 0
        ll L_sum = G0;
        ll R_sum = EA + EB - G1;
        ll L_diff = EB - EA - Margin1;
        ll R_diff = Margin0;

        // Basic consistency checks for intervals
        if (L_sum > R_sum || L_diff > R_diff) {
            cout << "NO" << endl;
            return;
        }

        // We check for the existence of an integer x (allocation of excess A to Type 0)
        // such that there exists a valid y (allocation of excess B to Type 0).
        // This reduces to finding the intersection of several intervals for x.
        
        // Initial bounds for x based on available Excess A
        ll x_min = 0;
        ll x_max = EA;

        // Derived from difference constraints: L_diff <= y - x <= R_diff
        // y >= 0 -> -x <= R_diff -> x >= -R_diff
        x_min = max(x_min, -R_diff);
        // y <= EB -> x + L_diff <= EB -> x <= EB - L_diff
        x_max = min(x_max, EB - L_diff);
        // y >= x + L_diff, y <= x + R_diff (coupled with sum) -> checks below covers full logic

        // Derived from sum constraints: L_sum <= x + y <= R_sum
        // y >= 0 -> x <= R_sum
        x_max = min(x_max, R_sum);
        // y <= EB -> x + L_sum <= EB -> x >= L_sum - EB
        x_min = max(x_min, L_sum - EB);

        // Derived from coupled constraints (substituting y bounds into x)
        // L_sum - x <= x + R_diff => 2x >= L_sum - R_diff
        x_min = max(x_min, ceil_div2(L_sum - R_diff));
        // x + L_diff <= R_sum - x => 2x <= R_sum - L_diff
        x_max = min(x_max, floor_div2(R_sum - L_diff));

        if (x_min <= x_max) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}