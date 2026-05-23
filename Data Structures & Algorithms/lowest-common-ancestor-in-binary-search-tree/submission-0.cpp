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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(p->val > q->val) return lowestCommonAncestor(root, q, p);
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;
        if(q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        if(q->val > root->val && p->val > root->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
