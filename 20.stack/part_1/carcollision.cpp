#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size(), left = 0, rght = n-1;
        while(left < n and directions[left] == 'L') left++;
        while(rght >= 0 and directions[rght] == 'R') rght--;

        int scnt = count(directions.begin()+left, directions.begin()+rght+1, 'S');
        return (rght - left + 1) - scnt;
    }
};

int main() {

    return 0;
}