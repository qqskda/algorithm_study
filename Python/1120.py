# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        # The function will be recursive that goes down to leaves.
        self.maxVal = 0 # Avg val to be compared at each calculation
        def traverse(node):
            if node is None: # if it is a leaf
                return [0,0] # [avgVal, # of descendants]
            
            # Each side 
            lsum, lcount = traverse(node.left)
            rsum, rcount = traverse(node.right)
            
            self.maxVal = max(self.maxVal, (lsum + rsum + node.val) / (lcount+rcount+1))
            return [lsum+rsum+node.val, lcount+rcount+1]
        traverse(root)
        return self.maxVal
            
            