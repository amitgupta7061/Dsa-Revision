#include <bits/stdc++.h>
using namespace std;

static unordered_map<string, int> order = {{"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};
bool cmp(tuple<string, string> &a, tuple<string, string> &b){
    if (get<1>(a) != get<1>(b))
        return order[get<1>(a)] < order[get<1>(b)];

    return get<0>(a) < get<0>(b);
}

class Solution {
public:
    bool validateCode(string code){
        if(!code.size()) return false;
        for(auto &ch : code){
            if(isalnum(ch)) continue;
            else if(ch == '_') continue;
            else return false;
        }
        return true;
    }
    bool validatebusinessLine(string business){
        return business == "electronics" or business == "grocery" or business == "pharmacy" or business == "restaurant";
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<tuple<string, string>> filtered;
        for(int i = 0; i < code.size(); i++){
            bool hasValidCode = validateCode(code[i]);
            bool hasValidBusiness = validatebusinessLine(businessLine[i]);
            bool hasActive = isActive[i];

            if(hasValidCode and hasValidBusiness and hasActive){
                filtered.push_back({code[i], businessLine[i]});
            }
        }

        sort(filtered.begin(), filtered.end(), cmp);
        vector<string> result;
        for(auto &str : filtered){
            result.push_back(get<0>(str));
        }

        return result;
    }
};

int main() {

    return 0;
}