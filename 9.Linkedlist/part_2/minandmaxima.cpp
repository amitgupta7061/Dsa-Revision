#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result(2, -1);
        if (!head || !head->next || !head->next->next) return result;

        int index = 1, first = -1, prev = -1;
        int minDist = INT_MAX;

        ListNode* prevNode = head;
        ListNode* curr = head->next;

        while (curr->next) {
            index++;
            if ((curr->val > prevNode->val && curr->val > curr->next->val) || 
                (curr->val < prevNode->val && curr->val < curr->next->val)) {
                
                if (first == -1) first = index;
                if (prev != -1) minDist = min(minDist, index - prev);
                prev = index;
            }
            prevNode = curr;
            curr = curr->next;
        }

        if (first == -1 || first == prev) return result;
        result[0] = minDist;
        result[1] = prev - first;
        return result;
    }
};


int main() {

    return 0;
}