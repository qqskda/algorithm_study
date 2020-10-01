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
    void diff(TreeNode* root, int max_, int min_, int *ret){
            if (root == NULL) return ;
            max_ = max(root->val, max_);
            min_ = min(root->val, min_);
            ret[0] = max(ret[0], max_ - min_);
            
            diff(root->left, max_, min_, ret);
            diff(root->right, max_, min_, ret);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ret[1] = {0}, max_ = INT_MIN, min_ = INT_MAX;
        diff(root, max_, min_, ret);
        return ret[0];
    }
};