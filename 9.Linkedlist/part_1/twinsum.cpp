#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(!head or !head->next) return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* f(ListNode* head){
        ListNode* slow = head; ListNode* fast = head;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode* mid = f(head);
        ListNode* sHead = reverse(mid->next);

        int maxi = -1;
        while(head){
            maxi = max(maxi, head->val + sHead->val);
            head = head->next; sHead = sHead->next;
        }
        return maxi;
    }
};


int main() {

    return 0;
}