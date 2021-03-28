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
        ListNode* fast = head;

        while (fast->next && fast->next->next){
            fast = fast->next->next;
            head = head->next;
            if (fast == head) return true;
        }
        return false;
    }
};

/*
Two Pointers: slow and fast
If there is a cycle -> There are eventually an intersection between slow and fast
*/
