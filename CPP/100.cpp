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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // It is a tree scanning.
        // If reached the leaf (both has no value) -> true
        if (!p && !q) return true;
        // p or q has value now. If either one has no value -> false
        if (!(p && q)) return false;
        // now p and q both has value
        if (p->val != q->val) return false;
        // now p and q both has the same value

        // Now current node has fully checked. Move on to the next ones
        return (isSameTree(p->left,q->left) && isSameTree(p->right, q->right));
    }
};
