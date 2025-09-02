#include <bits/stdc++.h>
using namespace std;


int main() {

    int a;
    cin>>a;

    long long n = a;

    while (n != 1)
    {
        cout<<n<<" ";
        if(n != 1){
            if(n % 2) n = (n * 3) + 1;
            else n = n / 2;
        }
    }

    cout<<"1";
    

    return 0;
}