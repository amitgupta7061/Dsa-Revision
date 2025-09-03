#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &set){
    cout<<set.size()<<"\n";

    for(auto &it : set){
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main() {

    int n;
    cin >> n;

    long long sum = ((long long)n * ((long long)n + 1)) / 2LL;
    if(sum % 2 == 0){
        cout<<"YES\n";
        long long target = sum / 2;
        vector<int> set1, set2;
        long long sum_set1 = 0;

        for(int i = n; i >= 1; i--){
            if(sum_set1 + i <= target){
                sum_set1 += i;
                set1.push_back(i);
            } else {
                set2.push_back(i);
            }
        }

        print(set1);
        print(set2);
    } else {
        cout<<"NO";
    }

    return 0;
}