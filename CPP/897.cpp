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

    TreeNode* increasingBST(TreeNode* root) {
        // tree walkthrough algorithm
        // Visit the lefts, reach the leaf -> scan the right one
        // left + itself + right
        TreeNode* ret = new TreeNode;
        TreeNode* start = ret;
        walkTree(root, ret);
        return start->right;
    }
    void walkTree(TreeNode* root, TreeNode*& ret){
        if (!root) return;

        // Check left
        walkTree(root->left, ret);
        // Add itself
        ret->right = new TreeNode(root->val);
        ret = ret->right;
        // Check right
        walkTree(root->right, ret);
    }

};
