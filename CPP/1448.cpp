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
    void DFS(TreeNode*& root, int farMax, int& count){
        if (!root) return;

        // if node >= farMax -> good
        if (root->val >= farMax){
            count++;
            farMax = max(root->val, farMax);
        }

        DFS(root->left, farMax, count);
        DFS(root->right, farMax, count);

    }

    int goodNodes(TreeNode* root) {
        int farMax = INT_MIN, count = 0;
        DFS(root, farMax, count);
        return count;
    }
};
