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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // https://en.cppreference.com/w/cpp/container/stack
                // Stack is useful in this case : LIFO
        stack<int> numL1, numL2;
        
        while (l1){
            numL1.push(l1->val);
            l1 = l1->next;
        }
        while (l2){
            numL2.push(l2->val);
            l2 = l2->next;
        }
        //Create return ListNode
        ListNode *retNode = new ListNode(0);
        retNode->next = nullptr;
        int bit_carry = 0, sum = 0, num1 = 0, num2 = 0;
        
        while (!numL1.empty() | !numL2.empty() | bit_carry){
            if (!numL1.empty()){
                num1 = numL1.top();
                numL1.pop();
            }
            if (!numL2.empty()){
                num2 = numL2.top();
                numL2.pop();
            }
            sum = num1 + num2 + bit_carry;
            bit_carry = sum / 10;
            sum %= 10;
            num1 = 0, num2 = 0; // Reset the values -> In case each ListNode length different.
            
            ListNode *tempNode = new ListNode(sum);
            // Anchor to retNode so that retNode->tempNode2->tempNode1...
            tempNode->next = retNode->next;
            retNode->next = tempNode;
        }
        return retNode->next;        
    }
};