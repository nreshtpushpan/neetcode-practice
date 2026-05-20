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
    pair<ListNode *, int> removeNode(ListNode *head, const int &n) {
        if(!head) return {NULL, 1};
        auto [node, len] = removeNode(head->next, n);
        if(len == n) {
            delete head;
            return {node, len+1};
        }
        head->next = node;
        return {head, len + 1};
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeNode(head, n).first;
    }
};
