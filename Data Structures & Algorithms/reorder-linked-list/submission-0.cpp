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
    ListNode *reverse(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *cur = head;
        while(cur) {
            auto nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto middle = slow->next;
        slow->next = nullptr;
        auto revH = reverse(middle);
        ListNode *cur = head;
        while(cur && revH) {
            auto nxt = cur->next;
            auto revNxt = revH->next;
            cur->next = revH;
            revH->next = nxt;
            cur = nxt;
            revH = revNxt;
        }
    }
};
