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

 // Iteration method
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        return checker(slow, head);
    }

    bool checker(ListNode*& slow, ListNode* fast){
        // if nullptr -> go back
        if (!fast) return true;
        // fast reaches the end and travel backward
        if (!checker(slow, fast->next)) return false;
        // compare values
        if (slow->val != fast->val) return false;
        // update slow (head)
        slow = slow->next;
        // Indicate so far so good.
        return true;
    }
};

// Read once - Other option: use stack and queue
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;

        while (head){
            vec.push_back(head->val);
            head = head->next;
        }

        for (int i = 0; i < vec.size() / 2; ++i){
            if (vec[i] != vec[vec.size()-1-i]) return false;
        }

        return true;
    }
};
