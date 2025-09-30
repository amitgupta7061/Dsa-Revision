#include <iostream>
using namespace std;


long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long g = extended_gcd(b % a, a, x1, y1);
    
    x = y1 - (b / a) * x1;
    y = x1;
    
    return g;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    a = a % m; 
    
    long long g = extended_gcd(a, m, x, y);

    if (g != 1) {
        return -1; 
    } else {
        return (x % m + m) % m;
    }
}

int main() {
    long long a = 3, m = 11;
    long long inv = modInverse(a, m);
    cout << "Inverse of " << a << " mod " << m << " is: " << inv << std::endl; 


    a = 6; m = 12;
    inv = modInverse(a, m);
    cout << "Inverse of " << a << " mod " << m << " is: " << inv << std::endl; 
    return 0;
}