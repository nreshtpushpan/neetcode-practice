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
    void recur(TreeNode *root, int maxVal, int &ans) {
        if(!root) return;
        if(root->val >= maxVal) ++ans;
        recur(root->left, max(root->val, maxVal), ans);
        recur(root->right, max(root->val, maxVal), ans);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        recur(root, -101, ans);
        return ans;
    }
};
