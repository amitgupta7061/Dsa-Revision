#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> seen;
        
        map<pair<long long, long long>, long long> parallelCount;
        map<tuple<long long, long long, long long>, long long> sameLineCount;
        map<tuple<long long, long long, long long>, long long> parallelSideCount;
        map<tuple<long long, long long, long long, long long>, long long> sameLineSideCount;
        
        long long result = 0;
        long long rhombusTwice = 0;
        
        auto normalize = [](long long dx, long long dy) -> pair<long long, long long> {
            if (dx == 0 && dy == 0) return {0, 0};
            long long g = __gcd(abs(dx), abs(dy));
            dx /= g; dy /= g;
            if (dx < 0 || (dx == 0 && dy < 0)) { dx = -dx; dy = -dy; }
            return {dx, dy};
        };
        
        for (int i = 0; i < n; i++) {
            long long x1 = points[i][0], y1 = points[i][1];
            for (auto& [x2, y2] : seen) {
                long long dx = x1 - x2;
                long long dy = y1 - y2;
                
                auto [ndx, ndy] = normalize(dx, dy);
                
                long long cross = ndy * x1 - ndx * y1;
                
                pair<long long, long long> slopeId = {ndx, ndy};
                tuple<long long, long long, long long> lineId = {ndx, ndy, cross};
                
                result += parallelCount[slopeId] - sameLineCount[lineId];
                
                parallelCount[slopeId]++;
                sameLineCount[lineId]++;
                
                long long sideLen = dx * dx + dy * dy;
                
                tuple<long long, long long, long long> slopeSide = {ndx, ndy, sideLen};
                tuple<long long, long long, long long, long long> lineSide = {ndx, ndy, cross, sideLen};
                
                rhombusTwice += parallelSideCount[slopeSide] - sameLineSideCount[lineSide];
                
                parallelSideCount[slopeSide]++;
                sameLineSideCount[lineSide]++;
            }
            seen.push_back({x1, y1});
        }
        
        return result - rhombusTwice / 2;
    }
};