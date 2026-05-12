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
    int findLength(ListNode *l) {
        if(!l) return 0;
        return 1 + findLength(l->next);
    }
    ListNode* addList(ListNode* a, ListNode* b, int carry) {
        if(!a) {
            if(carry) return new ListNode(carry);
            return NULL;
        }
        int aVal = a->val;
        int bVal = (b != NULL) ? b->val : 0;
        int sum = aVal + bVal + carry;
        int digit = sum%10;
        carry = sum/10;
        a->val = digit;
        a->next = addList(a->next, (b != NULL) ? b->next : NULL, carry);
        return a;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n = findLength(l1);
        int m = findLength(l2);
        if(m > n) return addTwoNumbers(l2, l1);
        return addList(l1, l2, 0);
    }
};
