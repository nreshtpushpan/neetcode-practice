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
    unordered_map<int, int> indexMap;
    int index = 0;
    TreeNode* build(const vector<int>& preorder, int l, int r) {
        if(l > r) return nullptr;
        int root_val = preorder[index++];
        TreeNode *root = new TreeNode(root_val);
        auto midIndex = indexMap[root_val];
        root->left = build(preorder, l, midIndex - 1);
        root->right = build(preorder, midIndex + 1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < (int)inorder.size(); i++) indexMap[inorder[i]] = i;
        return build(preorder, 0, (int)inorder.size()-1);
    }
};
