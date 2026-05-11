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
    void recur(TreeNode *root, int &k, int &res) {
        if(!root) return;
        recur(root->left, k, res);
        if(k == 1) res = root->val;
        recur(root->right, --k, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res, count = 0;
        recur(root, k, res);
        return res;
    }
};
