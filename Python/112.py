# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        return self.isTheSum(root, 0, targetSum)

    def isTheSum(self, root: TreeNode, currentSum: int, targetSum : int) -> bool:
        if not root: return False

        currentSum += root.val

        if not root.left and not root.right:
            if currentSum == targetSum:
                return True

        return self.isTheSum(root.left, currentSum, targetSum) or self.isTheSum(root.right, currentSum, targetSum)

# As noted, consider if the TreeNode has both positive and negative value at the sametime
# Which means we cannot know if we on the right path untill we reach each leaves.
