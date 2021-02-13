# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root: return True
        leftHeight = self.getHeight(root.left)
        rightHeight = self.getHeight(root.right)
        return abs(leftHeight - rightHeight) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)

    def getHeight(self, root: TreeNode) -> int:
        if not root:
            return 0
        else:
            leftHeight = self.getHeight(root.left)
            rightHeight = self.getHeight(root.right)
            return max(leftHeight, rightHeight) + 1
