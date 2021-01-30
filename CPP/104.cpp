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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        else{
            int lDepth = maxDepth(root->left);
            int rDepth = maxDepth(root->right);
            return max(lDepth, rDepth) + 1;
            // +1 will eventually stack from bottom to the top = maxDepth of the entire tree.
        }
    }
};
