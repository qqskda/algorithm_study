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
        ListNode* prev = nullptr;
        ListNode* next;
        while (head){
            // Save next nodes
            next = head->next;
            // set head->next to previous one (arrow change)
            head->next = prev;
            // Update previous to the head
            prev = head;
            // Update head to be the next one.
            head = next;
        }
        return prev;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* reversedRestNodes = reverseList(head->next);
        
        // Reverse the current node
        head->next->next = head;
        head->next = nullptr;
        return reversedRestNodes;
    }
};

/*
Reverse Linked List: 
1. need 2 pointers
*/