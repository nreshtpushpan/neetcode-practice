/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node *> vis;
    Node * recur(Node *node) {
        if(vis.count(node)) return vis[node];
        Node *newNode = new Node(node->val);
        vis[node] = newNode;
        for(auto childNode : node->neighbors) {
            newNode->neighbors.push_back(recur(childNode));
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        return recur(node);
    }
};
