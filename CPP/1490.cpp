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
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;

        vector<Node*> kids;
        for (auto child : root->children){
            Node* kid = cloneTree(child);
            kids.push_back(kid);
        }
        Node* ret = new Node(root->val, kids);
        return ret;
    }
};
