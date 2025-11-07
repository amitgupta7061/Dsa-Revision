#include <bits/stdc++.h>
using namespace std;

bool hasLeadingZero(string &s) {
    return s.size() > 1 && s[0] == '0';
}
string addStrings(string num1, string num2) {
    int i = num1.size() - 1, j = num2.size() - 1;
    string result = "";
    int carry = 0;
    while(i >= 0 and j >= 0){
        int fnum = (num1[i] - '0'), snum = (num2[j] - '0');
        int sum = carry + fnum + snum;
        carry = 0;
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
        carry = 0;
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
        carry = 0;
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
    if(carry) result = to_string(carry) + result;
    return result;
}


bool isSumStringHelper(string &s, long long first, long long second, int ind) {
    if (ind == s.size()) return true;

    long long sum = first + second;
    string sumStr = to_string(sum);

    if (s.substr(ind, sumStr.size()) == sumStr) {
        return isSumStringHelper(s, second, sum, ind + sumStr.size());
    }

    return false;
}

bool isSumString(string &s) {
    int n = s.size();
    for (int len1 = 1; len1 <= n / 2; len1++) {
        string firstStr = s.substr(0, len1);
        if (hasLeadingZero(firstStr)) continue;
        long long first = stoll(firstStr);
        for (int len2 = 1; max(len1, len2) <= n - len1 - len2; len2++) {
            string secondStr = s.substr(len1, len2);
            if (hasLeadingZero(secondStr)) continue;
            long long second = stoll(secondStr);
            if (isSumStringHelper(s, first, second, len1 + len2)) {
                return true;
            }
        }
    }

    return false;
}
