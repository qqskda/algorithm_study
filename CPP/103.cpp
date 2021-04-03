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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if (!root) return vec;

        int height = 1;
        stack<TreeNode*> fromLeft, fromRight;
        // height 1 == Read from right, add from left
        // height 0 == Read from left, add from right
        fromRight.push(root);

        while (!fromLeft.empty() || !fromRight.empty()){
            vector<int> v;

            if (height % 2 == 1){
                // odd -> fromRight
                while (!fromRight.empty()){
                    // Read from right
                    TreeNode* curr = fromRight.top();
                    fromRight.pop();
                    v.push_back(curr->val);

                    // Add its child (fromLeft)
                    if (curr->left) fromLeft.push(curr->left);
                    if (curr->right) fromLeft.push(curr->right);
                }
            } else {
                // even -> fromLeft
                while(!fromLeft.empty()){
                    // Read from left
                    TreeNode* curr = fromLeft.top();
                    fromLeft.pop();
                    v.push_back(curr->val);

                    // its child (fromRight)
                    if (curr->right) fromRight.push(curr->right);
                    if (curr->left) fromRight.push(curr->left);
                }
            }
            // Finished one level
            vec.push_back(v);
            // Go down
            height++;
        }

        return vec;
    }
};

/*
BFS - Simpllify the question:
1. Find a way to retrieve elements by its height (same level) - passing height
2. Find a way to swtich the travelling way (use height)

DS: stack.
*/
