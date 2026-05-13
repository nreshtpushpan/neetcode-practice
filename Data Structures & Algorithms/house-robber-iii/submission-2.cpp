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
    pair<int,int> recur(TreeNode *root) {
        if(!root) return {0, 0};
        auto [rob_left, skip_left] = recur(root->left);
        auto [rob_right, skip_right] = recur(root->right);
        int rob = root->val + skip_left + skip_right;
        int skip = max(rob_left, skip_left) + max(rob_right, skip_right);
        return {rob, skip};
    }
    int rob(TreeNode* root) {
        auto [leftMax, rightMax] = recur(root);
        return max(leftMax, rightMax);
    }
};