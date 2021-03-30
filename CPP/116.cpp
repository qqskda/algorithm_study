/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left) return root;
        queue<Node *> q;
        q.push(root); q.push(NULL);

        while (q.size()>1){
            // if q.front == NULL -> next level
            while (q.front() != NULL){
                Node* curr = q.front();
                q.pop(); // update queue
                curr->next = q.front();

                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
            // q.front() == NULL;
            // Insert new NULl at the end (new level)
            q.pop(); q.push(NULL);
        }
        return root;
    }
};

/*
Given Info:
1. Perfect Binary Tree
2. Connect to rightward

Ideas:
1. BFS

DataStructures: Queue FIFO -> connects curr ptr to first in the queue
Use NULL to mark height
*/
