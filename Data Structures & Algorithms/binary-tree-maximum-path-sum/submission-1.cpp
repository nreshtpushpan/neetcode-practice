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
    int recur(TreeNode *root, int &maxSum) {
        if(!root) return 0;
        auto l = recur(root->left, maxSum);
        auto r = recur(root->right, maxSum);
        maxSum = max({maxSum, root->val, root->val + l, root->val + r, root->val + l + r});
        return max({root->val, root->val + l, root->val + r});
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        recur(root, sum);
        return sum;
    }
};
