#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> haveToDel(nums.begin(), nums.end());

        ListNode* nHead = new ListNode(100);
        ListNode* curr = head;
        ListNode* temp = nHead;

        while(curr){
            if(!haveToDel.count(curr->val)){
                temp->next = curr;
                temp = curr;
            }
            curr = curr->next;
        }
        temp->next = NULL;
        return nHead->next;
    }
};

int main() {

    return 0;
}