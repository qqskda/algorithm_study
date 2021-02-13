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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return isTheSum(root, 0, targetSum);
    }

    bool isTheSum(TreeNode* root, int currentSum, int targetSum){
        // Not taking this path
        if (!root) return false;

        currentSum += root->val;

        if (!root->left && !root->right) {
             // if root is leaf
            if (currentSum == targetSum) return true;
        }
        return isTheSum(root->left, currentSum, targetSum)
             || isTheSum(root->right, currentSum, targetSum);
    }
};

// Consider the case that the elements in the TreeNode can be negative and positive at the same time.
// In that case, dont stop in the middle, but only consider the value when it is leaf.
