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
    void recur(TreeNode *root, const int &k, int &count, int &res) {
        if(!root) return;
        recur(root->left, k, count, res);
        if(count + 1 == k) res = root->val;
        ++count;
        recur(root->right, k, count, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res, count = 0;
        recur(root, k, count, res);
        return res;
    }
};
