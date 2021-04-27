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
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        
        while (head){
            vec.push_back(head->val);
            head = head->next;
        }
        
        // Now check palindrome
        for (int start = 0, end = vec.size()-1; start < end; ++start, --end){
            if (vec[start] != vec[end]) return false;
        }
        return true;
    }
};