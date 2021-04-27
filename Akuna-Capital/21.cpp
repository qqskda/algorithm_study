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
    
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (!l1 && !l2) return NULL;
        
        ListNode* output = new ListNode();
        ListNode* root = output;
        
        // Both
        while (l1 && l2){
            if (l1->val < l2->val){
                // l1 first
                output->next = l1;
                l1 = l1->next;
            } else {
                output->next = l2;
                l2 = l2->next;
            }
            output = output->next;
        }
        
        if (l1) output->next = l1;
        if (l2) output->next = l2;
        
        
        return root->next;
    }
};