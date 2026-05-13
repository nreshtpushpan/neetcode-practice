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
    map<pair<TreeNode *, bool>, int> dp;
    int recur(TreeNode *root, bool isValid) {
        if(!root) return 0;
        if(dp.count({root, isValid})) return dp[{root, isValid}];
        int ans = 0;
        if(isValid) {
            ans = root->val + recur(root->left, false) + recur(root->right, false);
        }
        ans = max(ans, recur(root->left, true) + recur(root->right, true));
        return dp[{root, isValid}] = ans;
    }
    int rob(TreeNode* root) {
        return max(recur(root, true), recur(root, false));
    }
};