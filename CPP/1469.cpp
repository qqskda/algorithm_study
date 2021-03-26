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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> table;
        helper(root, table);
        return table;
    }

    void helper(TreeNode* root, vector<int> &table){
        if (!root) return;

        if (root->left && root->right){
            helper(root->left, table);
            helper(root->right,table);
        } else if (root->left && !root->right) {
            table.push_back(root->left->val);
            helper(root->left, table);
        } else if (root->right && !root->left) {
            table.push_back(root->right->val);
            helper(root->right, table);
        }
    }
};
