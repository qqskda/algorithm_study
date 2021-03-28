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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;

        TreeNode* ret = new TreeNode();
        DFS(root1, ret);
        DFS(root2, ret);
        return ret;
    }

    // DFS
    void DFS(TreeNode* root, TreeNode* ret){
        if (!root) return;
        ret->val += root->val;

        if (root->left) {
            if (!ret->left) ret->left = new TreeNode();
            DFS(root->left, ret->left);
        }
        if (root->right){
            if (!ret->right) ret->right = new TreeNode();
            DFS(root->right, ret->right);
        }
    }
};
