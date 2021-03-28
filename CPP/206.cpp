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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        // while curr presents (head)
        while (curr){
            ListNode* temp = curr->next;
            // Next one points previuos one
            curr->next = prev;
            // prev is now curr
            prev = curr;
            // curr became (original) next one
            curr = temp;
        }

        //prev is the new head
        return prev;
    }

};

/*
Always think reverse LinkedList requires 2 pointers: prev, curr
*/ 
