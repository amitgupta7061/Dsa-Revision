#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarysearch(vector<int> &nums, int n){
        int low = 0, high = n - 1, ans = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] < 0){
                ans = mid; high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        for(int i = 0; i < m; i++){
            int ind = binarysearch(grid[i], n);
            cnt += n - ind;
        }
        return cnt;
    }
};

int main() {

    return 0;
}