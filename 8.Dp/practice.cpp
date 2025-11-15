#include <bits/stdc++.h>
using namespace std;

int minMultRec(vector<int> &nums, int i, int j){
    if(i+1 == j) return 0;
    int res = INT_MAX;

    for(int k = i + 1; k < j; k++){
        int curr = minMultRec(nums, k, j) + minMultRec(nums, i, k) + (nums[i] * nums[j] * nums[k]);
        res = min(res, curr);
    }

    return res;
}

int matrixMultiplication(vector<int> &arr){
    int n = arr.size();
    return minMultRec(arr, 0, n - 1);
}


int main() {

    return 0;
}