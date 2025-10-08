#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    int getsizeofLL(ListNode* head){
        if(head == nullptr) return 0;
        return 1 + getsizeofLL(head->next);
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> result(k);
        int length = getsizeofLL(root);
        int evHave = length / k, extra = length % k;

        ListNode* prev = nullptr;
        ListNode* head = root;

        for (int i = 0; i < k; ++i, --extra) {
            result[i] = head;
            for (int j = 0; j < evHave + (extra > 0); ++j) {
                prev = head;
                head = head->next;
            }
            if (prev != nullptr) prev->next = nullptr;
        }

        return result;
    }
};

int main() {

    return 0;
}