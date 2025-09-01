#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        auto gain = [&](int p, int t){
            return (double)(p+1) / (t+1) - (double)p/t;
        };

        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < classes.size(); i++){
            pq.push({gain(classes[i][0], classes[i][1]), i});
        }

        while(pq.size() and extraStudents){
            auto [ratio, ind] = pq.top(); pq.pop();
            classes[ind][0]++;
            classes[ind][1]++;
            pq.push({gain(classes[ind][0], classes[ind][1]), ind});
            extraStudents--;
        }

        double sum = 0;

        for(auto &it : classes){
            sum += (double)it[0] / (double)it[1];
        }

        return sum / (classes.size() * 1.0);
    }
};

int main() {

    return 0;
}