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

    void recur(TreeNode *root, vector<int> &preOrd) {
        if(!root) return;
        preOrd.push_back(root->val);
        recur(root->left, preOrd);
        recur(root->right, preOrd);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrd;
        recur(root, preOrd);
        return preOrd;
    }
};