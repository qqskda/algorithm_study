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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return {};
        // Edge Cases when the first element is the targeted value
        if (!head->next && head->val == val) return {};

        while(head->val == val){
            if (head->next) head = head->next;
            else return {};
        }

        // savepoint
        ListNode* root = head;

        while (head->next){
            // if not targeted value
            if (head->next->val != val){
                head = head->next;
                continue;
            }
            // if targeted value & end of the link
            if (!head->next->next){
                // if next is the end of the link
                head->next = nullptr;
                return root;
            }
            // if in the middle point->skip the next and recheck
            head->next = head->next->next;
        }
        return root;
    }
};

/*
Remove the given value in the given linked list
*/
