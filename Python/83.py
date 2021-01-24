# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        curNode = head;
        while(curNode and curNode.next):
            nextNode = curNode.next
            # val same: Update the curNode next - moving like iterator without updating
            if (curNode.val == nextNode.val): curNode.next = nextNode.next
            # else: curNode becomes the new val Node (head is still the root)
            else: curNode = nextNode

        return head
            
