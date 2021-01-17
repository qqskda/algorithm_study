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
        if (!l1 & !l2) return NULL;
        // Covered all the cases of empty lists

        ListNode *head; // Head that merges the two ListNodes

        if (l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        // Set the starting point for head
        ListNode *root = head;  // Set root that points the head of the merged list

        while(l1 && l2){
            if (l1->val < l2->val){
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head->next->next = NULL;
            // Because the while loop conditon, l1 or l2 will be not fully covered
            // But good to cover the NULL terminator
            head = head->next;
        }
        // Covered part of merge

        if (l1) head->next = l1;
        else head->next = l2;
        // Covered rest of the merge
        return root;

    }
};
