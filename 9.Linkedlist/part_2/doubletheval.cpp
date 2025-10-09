#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    int helper(ListNode* head) {
        if (!head) return 0;
        int carry = helper(head->next);
        int val = head->val * 2 + carry;
        head->val = val % 10;
        return val / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = helper(head);
        if (carry) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
};


int main() {

    return 0;
}