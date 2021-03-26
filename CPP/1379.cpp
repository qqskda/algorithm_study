/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // Remember we search it through the original tree
        // It is because traget points to an element in orignal.
        if (!original) return nullptr;
        // Original and Cloned gets updated at the same time.
        if (original == target) return cloned;

        // Try left first
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if (left) return left;
        return getTargetCopy(original->right, cloned->right, target);


    }
};

// It is a simple DFS to return the pointer of the target value while you search it on the original tree.
// Since target is the pointer within original, can compare with original tree, not with cloned.
