#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        string result = "";
        int carry = 0;
        while(i >= 0 and j >= 0){
            int fnum = (num1[i] - '0'), snum = (num2[j] - '0');
            int sum = carry + fnum + snum;
            if(sum > 9){
                int temp = sum % 10;
                sum /= 10;
                carry = sum;
                result = to_string(temp) + result;
            } else{
                result = to_string(sum) + result;
            }
            i--; j--;
        }
        while(i >= 0){
            int sum = carry + (num1[i] - '0');
            if(sum > 9){
                int temp = sum % 10;
                sum /= 10;
                carry = sum;
                result = to_string(temp) + result;
            }else{
                result = to_string(sum) + result;
            }
            i--;
        }
        while(j >= 0){
            int sum = carry + (num2[j] - '0');
            if(sum > 9){
                int temp = sum % 10;
                sum /= 10;
                carry = sum;
                result = to_string(temp) + result;
            }else{
                result = to_string(sum) + result;
            }
            j--;
        }
        return result;
    }
};

int main() {

    return 0;
}