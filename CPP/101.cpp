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
    bool isSymmetric(TreeNode* root) {
        // Scan the nodes in opposite ways
        if (!root) return true;
        // Tree is not empty
        else return isSame(root->left, root->right);
    }
    bool isSame(TreeNode *left, TreeNode *right){
        // In case both left and right are empty which is true
        if (!(left && right)) return left == right;
        // Left and Right are both not empty
        return ((left->val == right->val) && (isSame(left->right, right->left)) && (isSame(left->left, right->right)));
    }
};
