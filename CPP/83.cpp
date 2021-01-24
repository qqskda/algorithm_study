/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // itrNode is another head that moves along the link
        // itrNode is the new val node after the head.
        ListNode* itrNode = head;
        ListNode* nextNode;
        while (itrNode && itrNode->next){
            nextNode = itrNode->next;

            // Val Same: update the iterator without replace the node
            if(itrNode->val == nextNode->val) itrNode->next = nextNode->next;
            // If val is diff -> itrNode = new val node
            else itrNode = nextNode;
        }

        return head;
    }
};
