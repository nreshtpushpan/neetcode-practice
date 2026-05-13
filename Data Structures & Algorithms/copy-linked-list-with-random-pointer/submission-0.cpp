/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node *, Node *> cache;
    Node *create(Node *head) {
        if(!head) return NULL;
        if(cache.count(head)) return cache[head];
        Node* newNode = new Node(head->val);
        cache[head] = newNode;
        newNode->next = create(head->next);
        newNode->random = create(head->random);
        return newNode;
    }
    Node* copyRandomList(Node* head) {
        return create(head);
    }
};
