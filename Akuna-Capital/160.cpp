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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if both length to the intersection point same -> meet in the first place
        // if one side is shorter, it will reach the end without meeting -> switch it to the other
        // Meeting time = diff(legnthToIntersectino of A and B) * 2 switches

        ListNode* walkA = headA;
        ListNode* walkB = headB;
        
        while (walkA != walkB){

            walkA = (!walkA) ? headB : walkA->next;
            walkB = (!walkB) ? headA : walkB->next;
        }

        return walkB;
        
        
    }
};