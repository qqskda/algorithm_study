/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (slow != fast){
            // If fast reaches end -> there is no cycle
            if (!fast || !fast->next) return false;
            
            slow = slow->next;
            // It iss checked fast->next exists
            fast = fast->next->next;
        }
        
        return true;
    }
};

// Cycle Detection: Floyd's ALgorithm