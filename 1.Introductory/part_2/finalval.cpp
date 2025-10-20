#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for(string &opr : operations){
            if(opr[0] == '-' or opr[2] == '-') --val;
            else ++val;
        }
        return val;
    }
};

int main() {

    return 0;
}