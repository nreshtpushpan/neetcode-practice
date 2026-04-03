/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {

        if(!h1) return h2;
        if(!h2) return h1;
        ListNode dummy(0);
        ListNode *cur = &dummy;

        while(h1 && h2) {
            if(h1->val <= h2->val) {
                cur->next = h1;
                h1 = h1->next;
            } else {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
        }

        if(h1) cur->next = h1;
        if(h2) cur->next = h2;

        return dummy.next;
    }
};
