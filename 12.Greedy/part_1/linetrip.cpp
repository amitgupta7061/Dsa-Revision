#include <bits/stdc++.h>
using namespace std;


int main() {

    int testcases;
    cin >> testcases;

    while(testcases--){
        int n, x;
        cin >> n >> x;

        vector<int> fuelstation(n);
        for(int i = 0; i < n; i++){
            cin >> fuelstation[i];
        }

        if(n){
            int maxtank = 0;
            maxtank = max(maxtank, fuelstation[0] - 0);
            for(int i = 1; i < n; i++){
                maxtank = max(maxtank, fuelstation[i] - fuelstation[i-1]);
            }
            maxtank = max(maxtank, (x-fuelstation.back())*2);

            cout<<maxtank<<"\n";
        } else {
            cout<<2*x<<"\n";
        }
    }

    return 0;
}