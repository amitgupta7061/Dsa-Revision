#include <bits/stdc++.h>
using namespace std;

vector<int> maxSumSubarray(vector<int> &arr) {

    int resStart = 0, resEnd = 0;
    int currStart = 0;
    int maxSum = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {
      
        if(maxEnding + arr[i] < arr[i]) {
        	maxEnding = arr[i]; 
            currStart = i;
        }
        else {
            maxEnding += arr[i];
        }
        if(maxEnding > maxSum) {
            maxSum = maxEnding;
        	resStart = currStart;
            resEnd = i;
        }
    }
  
    vector<int> res;
    for(int i = resStart; i <= resEnd; i++)
        res.push_back(arr[i]);
    return res;
}
