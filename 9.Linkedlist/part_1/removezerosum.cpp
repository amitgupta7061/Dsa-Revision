#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> map;
        int sum = 0;
        ListNode* curr = dummy;

        while (curr) {
            sum += curr->val;
            map[sum] = curr;
            curr = curr->next;
        }

        sum = 0;
        curr = dummy;
        while (curr) {
            sum += curr->val;
            curr->next = map[sum]->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};


int main() {

    return 0;
}