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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seqs;
        // Get seq of root1
        walker(root1, seqs);
        // Get leaves of root2 and pop if order da same.
        checker(root2, seqs);
        return (seqs.size()) ? false : true;
    }

    void walker(TreeNode* root, vector<int>& seqs){
        if (!root) return;

        walker(root->left, seqs);

        // Check if it is a leaf
        if (!root->left && !root->right) {
            seqs.push_back(root->val);
            cout << root->val << endl;
        }

        walker(root->right, seqs);
    }

    void checker(TreeNode* root, vector<int>& seqs){
        if (!root) return;
        // Go backward using pop()
        checker(root->right, seqs);
        if (!root->left && !root->right){
            if (seqs.back() == root->val) seqs.pop_back();
            else {
                // In case root2 has more leaves
                // Add it to seqs: Now order is diff -> no popping happens.
                seqs.push_back(root->val);
                return;
            }
        }
        checker(root->left, seqs);
    }
};


// Compare the sequence of leaves
// 1. Walk together and lively compare -> may compicate stuff
// 2. Walk one first and lively compare the second one with the previous -> prob easier
