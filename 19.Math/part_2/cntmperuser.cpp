#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<string> &a, vector<string> &b){
    int t1 = stoi(a[1]), t2 = stoi(b[1]);
    if(t1 == t2) return a[0][0] > b[0][0];
    return t1 < t2;
}

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), cmp);
        vector<int> result(numberOfUsers, 0), status(numberOfUsers, -1);

        for(auto &it : events){
            string msgType = it[0];
            int time = stoi(it[1]);
            string mention = it[2];

            if(msgType == "MESSAGE"){
                if(mention == "ALL"){
                    for(auto &it : result) it++;
                } else if(mention == "HERE"){
                    for(int i = 0; i < numberOfUsers; i++){
                        if(status[i] == -1) result[i]++;
                        else {
                            if(status[i]+60 <= time) result[i]++;
                        }
                    }
                } else{
                    stringstream ss(mention);
                    string id;

                    while(getline(ss, id, ' ')){
                        int idd = stoi(id.substr(2));
                        result[idd]++;
                    }
                }
            } else{
                int userid = stoi(it[2]);
                status[userid] = time;
            }
        }
        return result;
    }
};

int main() {

    return 0;
}