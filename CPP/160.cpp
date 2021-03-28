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
        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB){
            pA = (!pA) ? headB : pA->next;
            pB = (!pB) ? headA : pB->next;
        }

        return pA;
    }
};

/*
Two Method: headA.len = n, headB.len = m

1. Two pointers -> Using diff in length (if same length -> get at the first try)
if abs(n-m) = 3 -> two pointers intersect at 3rd time of scanning.
Time: O(3 * (n+m)) space = O(1)

If there is no intersect:
1. Same Length -> Meet at nullptr
2. Diff Length -> once pointer catch up the other one eventually.

2. Hash
Time: O(min(n,m) if intersetcs || n+m if not). Space = O(n || m).
*/
