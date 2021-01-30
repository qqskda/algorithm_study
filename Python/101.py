# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def isSame(left: TreeNode, right: TreeNode):
    if not (left and right): # When either one is empty
        return left == right # In case both are empty
    else:
        return ((left.val == right.val) and (isSame(left.right, right.left)) and (isSame(left.left, right.right)))

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root: return True
        else: return isSame(root.left, root.right)
