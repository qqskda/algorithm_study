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
// Using vector<int> - 36ms
class Solution {
        vector<int> traverse(TreeNode* root, double &retVal){
        if (root == NULL) return {0,0};
        
        vector<int> left = traverse(root->left, retVal);
        vector<int> right = traverse(root->right, retVal);
        
        double compVal = ((double)(left[0] + right[0] + root->val)) / ((double)(left[1] + right[1] + 1));
        retVal = max(retVal, compVal);
        return {left[0] + right[0] + root->val, left[1] + right[1] + 1};
    }
public:  
    double maximumAverageSubtree(TreeNode* root) {
        double ret = 0;
        traverse(root, ret);
        return ret;
    }
};

// Using struct - 16ms
class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        max_avg_ = 0.0;
        dfs(root);
        return max_avg_;
    }
    
private:
    struct NodeInfo{
        int val_sum;
        int num_nodes;
    };
    
    NodeInfo dfs(TreeNode* node){
        if(node == nullptr) return {.val_sum = 0, .num_nodes = 0};
        
        NodeInfo left = dfs(node->left);
        NodeInfo right = dfs(node->right);
        
        NodeInfo ret{.val_sum = left.val_sum + right.val_sum + node->val,
                     .num_nodes = left.num_nodes + right.num_nodes + 1};
        
        double avg = (double)ret.val_sum / ret.num_nodes;
        if(avg > max_avg_) max_avg_ = avg;
        
        return ret;
    }  
    double max_avg_ = 0.0;
};