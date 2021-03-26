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
    int xDepth = 0, yDepth = 0;
    int xParent = 0, yParent = 0;

    bool isCousins(TreeNode* root, int x, int y) {
        int rootVal = root->val;
        if (x == rootVal || y == rootVal) return false;

        searcher(root, x, y, 0, root->val);

        if (xDepth == yDepth && xParent != yParent) return true;
        else return false;
    }

    void searcher(TreeNode* root, int x, int y, int curDepth, int parent){
        if (!root) return;

        if (root->val == x){
            xDepth = curDepth;
            xParent = parent;
            return;
        }

        if (root->val == y){
            yDepth = curDepth;
            yParent = parent;
            return;
        }

        // In case not found
        // Left and Right search
        searcher(root->left, x, y, curDepth + 1, root->val);
        searcher(root->right, x, y, curDepth + 1, root->val);
    }



};

/*
while searching record parent
Conditions:
1. Not the same parent
2. same Depth

Compare once the searching completed
*/
