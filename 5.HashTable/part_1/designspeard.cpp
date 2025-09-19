#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
public:
    unordered_map<string, int> spreadsheet;
    int getToken(const string& token) {
        return isdigit(token[0]) ? stoi(token)
                : (spreadsheet.count(token) ? spreadsheet[token] : 0);
    }
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) {
        spreadsheet[cell] = value;
    }

    void resetCell(string cell) {
        spreadsheet[cell] = 0;
    }

    int getValue(string formula) {
        int i = formula.find('+');
        return getToken(formula.substr(1, i - 1)) + getToken(formula.substr(i + 1));
    }
};

int main() {

    return 0;
}