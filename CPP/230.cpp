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
    vector<int> vec;
    int kthSmallest(TreeNode* root, int k) {
        bool flag = false;
        walk(root, k, flag);
        return vec.back();
    }
    void walk(TreeNode*& root, int& k, bool& flag){
        if (!root) return;
        if (flag) return;

        walk(root->left, k, flag);
        if (!flag) vec.push_back(root->val);
        if (vec.size() == k) flag = true;
        walk(root->right, k, flag);
    }
};
