#include<bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        vector<int> left(200005), right(200005), active(200005);
        vector<long long> val(200005);

        int n;
        cin >> n;
        set<pair<long long, int>> pq;

        int merge = 0;
        long long total = 0;

        for (int i = 0; i < n; ++i) {
            cin >> val[i];
            left[i] = (i - 1 + n) % n;
            active[i] = true;
            right[i] = (i + 1) % n;
        }

        if (n == 1) {
            cout<<0<<"\n"; continue;;
        }

        for (int i = 0; i < n; i++) {
            long long c = max(val[i], val[right[i]]);
            pq.insert({c, i});
        }

        while (merge < n - 1) {
            auto curr = *pq.begin();
            pq.erase(pq.begin());

            long long c = curr.first;
            int i = curr.second, j = right[i];

            if (!active[i] or !active[j]) continue;
            total += c;
            merge++;

            active[j] = false;
            val[i] = max(val[i], val[j]);

            int l = left[i], k = right[j];
            right[l] = i;
            left[i] = l;
            right[i] = k;
            left[k] = i;

            if (merge < n - 1) { 
                pq.insert({max(val[l], val[i]), l});
                pq.insert({max(val[i], val[k]), i});
            }
        }

        cout<<total<<"\n";
    }
    return 0;
}

