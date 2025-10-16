#include <bits/stdc++.h>
using namespace std;

int f(int X, int Y) {
    int maxVal = max(X, Y);
    for (int j = maxVal; j >= 1; j--) {
        if (X % j != 0 && Y % j != 0)  return j;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test;
    cin >> test;
    
    while (test--) {
        int N;
        cin >> N;
        
        vector<int> nums(N);
        int maxi = 0;
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
            maxi = max(maxi, nums[i]);
        }
        
        int maxGcnd = 0;
        vector<int> ind(N);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](int i, int j) {
            return nums[i] > nums[j];
        });
        
        for (int i = 0; i < N && maxGcnd < nums[ind[i]]; i++) {
            for (int j = i + 1; j < N; j++) {
                int currentGcnd = f(nums[ind[i]], nums[ind[j]]);
                maxGcnd = max(maxGcnd, currentGcnd);
    
                if (currentGcnd >= max(nums[ind[i]], nums[ind[j]]) - 1) {
                    break;
                }
            }
        }
        
        cout << maxGcnd << "\n";
    }
    
    return 0;
}