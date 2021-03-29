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
    vector<int> ret;
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        walk(root);
        return ret;
    }

    void walk(TreeNode* root){
        if (!root) return;

        walk(root->left);
        ret.push_back(root->val);
        walk(root->right);
    }


};
