# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root: return 0
        if not root.left and not root.right: return 1
        ld = self.minDepth(root.left)
        rd = self.minDepth(root.right)
        if (root.left and root.right):
            return 1 + min(ld, rd)
        else:
            return 1 + max(ld, rd)
