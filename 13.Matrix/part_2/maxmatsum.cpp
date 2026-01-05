#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX, n = matrix.size(), cnt = 0;
        long long sum = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0){
                    cnt++; mini = min(mini, matrix[i][j]);
                }
            }
        }
        if(cnt % 2 == 0) return sum;
        else return sum - abs(mini);
    }
};

int main() {

    return 0;
}