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
    
    template <class T> void swap(T& a, T& b){
        T temp = a;
        a = b;
        b = temp;
    }
    
    void DFS(TreeNode* root){
        if (!root) return;
        
        swap(root->left, root->right);
        DFS(root->left);
        DFS(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        DFS(root);
        return root;
    }
};