#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
      
        string result;
      
        bool isNegative = (numerator > 0) ^ (denominator > 0);
        if (isNegative) result += "-";
      
        long long dividend = abs(static_cast<long long>(numerator));
        long long divisor = abs(static_cast<long long>(denominator));
      
        result += to_string(dividend / divisor);
      
        dividend %= divisor;
      
        if (dividend == 0) return result;
      
        result += ".";
      
        unordered_map<long long, int> remainderToPosition;
      
        while (dividend != 0) {
            remainderToPosition[dividend] = result.size();
          
            dividend *= 10;
          
            result += to_string(dividend / divisor);
          
            dividend %= divisor;
          
            if (remainderToPosition.count(dividend)) {
                result.insert(remainderToPosition[dividend], "(");
                result += ")";
                break;
            }
        }
      
        return result;
    }
};


int main() {

    return 0;
}