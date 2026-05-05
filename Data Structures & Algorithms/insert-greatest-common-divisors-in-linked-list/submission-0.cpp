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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head) return head;
        ListNode *cur = head;
        while(cur && cur->next) {
            int gcd = __gcd(cur->val, cur->next->val);
            ListNode *nxt = cur->next;
            cur->next = new ListNode(gcd, nxt);
            cur = cur->next->next;
        }
        return head;

    }
};