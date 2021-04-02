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
private:
    vector<vector<int>> vec;
public:
    void BFS(vector<vector<int>>& vec, TreeNode*& root, int height){

        if (!root) return;

        // if this height is not visited -> expand the vec.
        if (vec.size() < height + 1){
            if (root->left || root->right){
                vec.push_back({});
            }
        }

        // Insert elements at height list
        if (root->left) vec[height].push_back(root->left->val);
        if (root->right) vec[height].push_back(root->right->val);

        // Visit its child node
        BFS(vec, root->left, height+1);
        BFS(vec, root->right, height+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vec.push_back({root->val});
        BFS(vec, root, 1);
        return vec;
    }
};
/*
BFS - Append the same level node into a list + add its child level from leftside.

*/
