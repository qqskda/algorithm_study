/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDep = 0;
    int maxDepth(Node* root) {
        if (!root) return 0;
        getHeight(root, 1);
        return maxDep;
    }

    void getHeight(Node* root, int currentHeight){
        if (!root) return;
        // Update current level detph
        maxDep = max(maxDep, currentHeight);

        for (auto child : root->children){
            getHeight(child, currentHeight + 1);
        }
    }
};
