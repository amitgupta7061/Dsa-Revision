#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string helper(int num, unordered_map<int, string>& belowTen,
                  unordered_map<int, string>& belowTwenty,
                  unordered_map<int, string>& belowHundred) {
        if (num == 0) return "";
        else if (num < 10) return " " + belowTen[num];
        else if (num < 20) return " " + belowTwenty[num];
        else if (num < 100) return " " + belowHundred[num / 10 * 10] + helper(num % 10, belowTen, belowTwenty, belowHundred);
        else if (num < 1000) return " " + belowTen[num / 100] + " Hundred" + helper(num % 100, belowTen, belowTwenty, belowHundred);
        else if (num < 1'000'000) return helper(num / 1000, belowTen, belowTwenty, belowHundred) + " Thousand" + helper(num % 1000, belowTen, belowTwenty, belowHundred);
        else if (num < 1'000'000'000) return helper(num / 1'000'000, belowTen, belowTwenty, belowHundred) + " Million" + helper(num % 1'000'000, belowTen, belowTwenty, belowHundred);
        else return helper(num / 1'000'000'000, belowTen, belowTwenty, belowHundred) + " Billion" + helper(num % 1'000'000'000, belowTen, belowTwenty, belowHundred);
    }
    string numberToWords(int num) {
        unordered_map<int, string> belowTen({
            {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
            {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}
        });
        unordered_map<int, string> belowTwenty({
            {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
            {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}
        });
        unordered_map<int, string> belowHundred({
            {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
            {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
        });

        if (num == 0) return "Zero";
        return helper(num, belowTen, belowTwenty, belowHundred).substr(1);
    }
};

int main() {

    return 0;
}