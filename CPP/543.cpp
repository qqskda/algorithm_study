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
    int diameterOfBinaryTree(TreeNode* root) {
        int farMax = 0;
        getSub(root, farMax);
        return farMax;
    }

    int getSub(TreeNode* root, int &soFarMax){
        if (!root) return 0;

        int left = getSub(root->left, soFarMax);
        int right = getSub(root->right, soFarMax);

        // Update max length so far
        soFarMax = max(soFarMax, left+right);

        // Return the longest path (one side)
        return max(left, right) + 1;
    }
};

/*
Find the longest diameter (between two nodes)
*/
