#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p = NULL;
        ListNode* q = NULL;

        int cnt = 0;
        ListNode* curr = list1;
        while(curr){
            cnt++;
            if(cnt == a) p = curr;
            if(cnt == b+1) q = curr;
            if(p and q) break;
            curr = curr->next;
        }

        p->next = list2;
        curr = list2;

        while(curr->next) curr = curr->next;
        curr->next = q->next;

        return list1;
    }
};

int main() {

    return 0;
}