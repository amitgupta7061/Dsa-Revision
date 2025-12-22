#include <iostream>
#include <vector>

using namespace std;

void solve() {
    long long n, k;
    if (!(cin >> n >> k)) return;

    if (k % 2 != 0) {
        // k is odd: maximize everything to n
        for (int i = 0; i < k; ++i) {
            cout << n << (i == k - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    // k is even: use k-2 copies of n and maximize the remaining pair
    vector<int> set_bits;
    for (int i = 30; i >= 0; --i) {
        if ((n >> i) & 1) set_bits.push_back(i);
    }

    if (set_bits.size() < 2) {
        // n is a power of 2: cannot improve over (k-1)*n
        for (int i = 0; i < k - 1; ++i) cout << n << " ";
        cout << "0\n";
    } else {
        int p1 = set_bits[0];
        int p2 = set_bits[1];
        long long X = 0;
        // Collect all bits where n has 0 below the second highest set bit
        for (int i = 0; i < p2; ++i) {
            if (!((n >> i) & 1)) {
                X |= (1LL << i);
            }
        }

        long long a = (1LL << p1) | X;
        long long b = (n ^ (1LL << p1)) | X;

        for (int i = 0; i < k - 2; ++i) cout << n << " ";
        cout << a << " " << b << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}