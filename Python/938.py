# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        # USE DFS, stop by the value range - target value <> current node val
        # If current node val is lower than low -> scan right child vice versa
        if root == None: return 0
        # Scan only one side -> root.val is not within the range
        if root.val < low: return self.rangeSumBST(root.right, low, high)
        if root.val > high: return self.rangeSumBST(root.left, low, high)

        return (root.val + self.rangeSumBST(root.right, low,high) + self.rangeSumBST(root.left, low, high))

        
