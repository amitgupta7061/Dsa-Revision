#include <bits/stdc++.h>
using namespace std;


void filleven(int n, vector<int> &result){
    for(int i = 2; i <= n; i++){
        if(i % 2 == 0) result.push_back(i);
    }
}

void fillodd(int n, vector<int> &result){
    for(int i = 1; i <= n; i++){
        if(i % 2) result.push_back(i);
    }
}
int main() {

    int n;
    cin >> n;

    if(n == 2 or n == 3){
        cout<<"NO SOLUTION";
        return 0;
    }

    vector<int> result;

    filleven(n, result);
    fillodd(n, result);

    for(auto &it : result){
        cout<<it<<" ";
    }

    return 0;
}