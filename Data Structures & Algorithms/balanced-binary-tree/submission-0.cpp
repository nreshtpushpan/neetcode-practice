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
    int recur(TreeNode *root, bool &isBal) {
        if(!root) return 0;
        auto l = recur(root->left, isBal);
        auto r = recur(root->right, isBal);
        isBal &= (abs(l - r) < 2);
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        bool isBal = true;
        recur(root, isBal);
        return isBal;
    }
};
