/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    unordered_map<Node*, NodeCopy*> table;
    NodeCopy* copyRandomBinaryTree(Node* root) {
        builder(root);
        setter(root);
        return table[root];
    }

    void builder(Node* root){
        // if the current root is null -> Dont do anything
        if (!root) return;
        table[root] = new NodeCopy(root->val);
        builder(root->left);
        builder(root->right);
    }

    void setter(Node* root){
        if (!root) return;
        table[root]->left = table[root->left];
        table[root]->right = table[root->right];
        table[root]->random = table[root->random];

        setter(root->left);
        setter(root->right);
    }
};

/*
I do not see particular benefits of cloning the tree by one scanning as it may overcomplicate things
Hence, costs more than going over the tree twice.

*/
