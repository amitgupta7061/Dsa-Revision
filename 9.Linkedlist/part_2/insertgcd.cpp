#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            int g = gcd(curr->val, curr->next->val);
            ListNode* node = new ListNode(g);
            node->next = curr->next;
            curr->next = node;
            curr = node->next;
        }
        return head;
    }
};


int main() {

    return 0;
}