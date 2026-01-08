#include <bits/stdc++.h>
using namespace std;

int getpivot(vector<int> &nums, int l, int r){
    int pivot = nums[r], i = l - 1;
    for(int j = l; j < r; j++){
        if(nums[j] <= pivot){
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[r]);
    return i+1;
}

void quickSort(vector<int> &nums, int l, int r){
    if(l < r){
        int pivot = getpivot(nums, l, r);
        quickSort(nums, l, pivot-1);
        quickSort(nums, pivot+1, r);
    }
}

int main() {
    vector<int> nums = {10, 7, 8, 9, 1, 5};
    quickSort(nums, 0, nums.size() - 1);

    for (int x : nums) cout << x << " ";
    return 0;
}