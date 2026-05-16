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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        ListNode *cur = head;
        ListNode *left = head;
        ListNode *lf = NULL;
        int index = 1;
        while(cur && index <= r) {
            if(index+1 == l) lf = cur;
            if(index == l) left = cur;
            cur = cur->next;
            ++index;
        }
        ListNode * revCur = left;
        ListNode * leftPrev = lf;
        while(revCur != cur) {
            ListNode *nxt = revCur->next;
            revCur->next = leftPrev;
            leftPrev = revCur;
            revCur = nxt;
        }
        if(lf) lf->next = leftPrev;
        else head = leftPrev;
        left->next = cur;
        return head;
    }
};