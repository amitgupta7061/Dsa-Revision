#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        int maxi = 0, ans = 0;

        for (auto &event : events) {
            int srt = event[0], end = event[1], val = event[2];
            while (!pq.empty() && pq.top().first < srt) {
                maxi = max(maxi, pq.top().second);
                pq.pop();
            }
            ans = max(ans, maxi + val);
            pq.push({end, val});
        }

        return ans;
    }
};


int main() {

    return 0;
}