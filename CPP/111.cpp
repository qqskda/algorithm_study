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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (isLeaf(root)) return 1;
        int ld = minDepth(root->left);
        int rd = minDepth(root->right);
        if (root->right && root->left)
        // Node is both sided -> choose the shorter one
            return 1 + min(ld, rd);
        // Node is one sided -> choose the non-zero one
        else  return 1 + max(ld, rd);
    }

    bool isLeaf(TreeNode* root){
        if (!root->left && !root->right) return true;
        else return false;
    }
};
