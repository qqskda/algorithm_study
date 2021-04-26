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
    
    void DFS(TreeNode* root, TreeNode* output){
        if (!root) return;
        
        output->val += root->val;
        
        if (root->left){
            if(!output->left) output->left = new TreeNode();
            DFS(root->left, output->left);
        }
        
        if (root->right){
            if(!output->right) output->right = new TreeNode();
            DFS(root->right, output->right);
        }
        
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        
        TreeNode* output = new TreeNode();
        DFS(root1, output);
        DFS(root2, output);
        return output;
    }
};

/*
Conduct DFS for both root1 and root2 and update output TreeNode*

Do not conduct BFS -> overcomplicate the problem
*/