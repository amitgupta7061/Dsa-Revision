#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n, int k){
        if(n == 1) return 0;
        int ind = f(n-1, k);
        ind = (ind + k) % n;
        return ind;
    }
    int findTheWinner(int n, int k) {
        return f(n, k) + 1;
    }
};

int main() {

    return 0;
}