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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode*& a, ListNode* &b) {
            return a->val > b->val;  // min-heap by first element
        };
        priority_queue<ListNode*, vector<ListNode *>, decltype(cmp)> pq(cmp);
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        for(auto node: lists) {
            if(node) pq.push(node);
        }

        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            if(node->next) pq.push(node->next);
        }
        return (head->next) ? head->next : NULL;
    }
};
