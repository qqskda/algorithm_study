# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        # check if both p and q are empty
        if (not p and not q):
            return True
        # p or q are not empty
        if (not (p and q)):
            return False
        # p and q both are not empty
        if (p.val != q.val):
            return False
        # p and q have the same value
        # Now check the lower node
        return (self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right))
        
