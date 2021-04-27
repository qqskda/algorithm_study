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
    
    int walk(TreeNode* root, int height){
        if (!root) return 0;
        
        
        int ldepth = walk(root->left, height);
        int rdepth = walk(root->right, height);
        
        return max(ldepth, rdepth) + 1;
        
    }
    
    int maxDepth(TreeNode* root) {
        return walk(root, 1);
    }
};

/*
BFS
*/