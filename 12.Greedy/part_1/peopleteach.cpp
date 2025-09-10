#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadUsers;
        for(auto &it : friendships){
            int u1 = it[0] - 1, u2 = it[1] - 1;
            unordered_set<int> langset(languages[u1].begin(), languages[u1].end());
            bool canTalk = false;

            for(auto &l : languages[u2]){
                if(langset.count(l)){
                    canTalk = true; break;
                }
            }

            if(!canTalk){
                sadUsers.insert(u1);
                sadUsers.insert(u2);
            }
        }

        // find common max language
        int maxpeopleknow = 0;
        vector<int> knownlang(n+1, 0);
        for(auto &user : sadUsers){
            for(auto &lang : languages[user]){
                knownlang[lang]++;
                maxpeopleknow = max(maxpeopleknow, knownlang[lang]);
            }
        }

        return sadUsers.size() - maxpeopleknow;
    }
};

int main() {

    return 0;
}