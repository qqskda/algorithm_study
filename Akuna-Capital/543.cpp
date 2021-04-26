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
    
    int getDiameter(TreeNode* root, int& farMax){
        if (!root) return 0;
        
        int left = getDiameter(root->left, farMax);
        int right = getDiameter(root->right, farMax);
        
        farMax = max(farMax, left+right);
        
        // return one side
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int farMax = 0;
        getDiameter(root, farMax);
        
        return farMax;
    }
};

/*
Diameter of a node = maxLeftDepth + maxRightDepth
There is no guarantee that the root has the longest diameter
*/