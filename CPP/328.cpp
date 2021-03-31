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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        // head will be oddHead
        ListNode* odd = head, *even = head->next, *evenHead = even;

        while (odd->next && even->next){
            // even->next == odd->next->next
            odd->next = even->next;
            // Update odd to odd->next (even->next->next)
            odd = odd->next;
            even->next = odd->next;
            // Update even
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

/*
Need:
1. head, and last ptr for odd
2. head, and last ptr for even
*/
