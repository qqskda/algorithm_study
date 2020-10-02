# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        stackOne = [] # Stack implementation using list
        stackTwo = []
        while l1:
            stackOne.append(l1.val)
            l1 = l1.next
        while l2:
            stackTwo.append(l2.val)
            l2 = l2.next
        # Create return ListNode
        ret = ListNode(0, None)
        carry = 0; sum = 0; num1 =0; num2 = 0
        while stackOne or stackTwo or carry:
            if stackOne:
                num1 = stackOne[-1]
                stackOne.pop()
            if stackTwo:
                num2 = stackTwo[-1]
                stackTwo.pop()

            sum = num1 + num2 + carry
            carry = sum // 10 # To avoid having floats.
            sum %= 10
            num1 = 0; num2=0
            temp = ListNode(sum, ret.next)
            ret.next = temp
        
        return ret.next
        
        
        