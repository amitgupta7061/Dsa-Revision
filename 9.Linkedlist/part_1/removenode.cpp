#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == NULL) return NULL;
        head->next = removeNodes(head->next);
        return head->next != NULL && head->val < head->next->val ? head->next : head;
    }
};

int main() {

    return 0;
}