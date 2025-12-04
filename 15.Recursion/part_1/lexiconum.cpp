#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(int n, int curr, vector<int> result){
        if(curr > n) return;
        if(curr) result.push_back(curr);
        for(int i = (curr == 0 ? 1 : 0); i <= 9; i++){
            f(n, 10*curr+i, result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        f(n, 1, result);
        return result;
    }
};

int main() {

    return 0;
}