#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* srt = NULL;  
        ListNode* end = NULL;

        for (ListNode* curr = head; curr != NULL; curr = curr->next) {
            if (end != NULL) end = end->next;
            if (--k == 0) {
                srt = curr;
                end = head;
            }
        }

        swap(srt->val, end->val);
        return head;
    }
};

int main() {

    return 0;
}