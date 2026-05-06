/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> h;
        queue<pair<int,TreeNode*>> q;
        q.push({1, root});
        while(!q.empty()) {
            auto [height, node] = q.front();
            q.pop();
            if(h.size() < height) h.push_back(node->val);
            else h[height - 1] = node->val;
            if(node->left) q.push({height + 1, node->left});
            if(node->right) q.push({height + 1, node->right});
        }
        return h;
    }
};
