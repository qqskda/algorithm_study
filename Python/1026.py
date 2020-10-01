# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Save path values in a list
class Solution:
    def dfs(self, root, path):
        if not root: # If root is null
            # Update the returnVal of the node
            self.returnVal = max(self.returnVal, max(path) - min(path)) 
            return
        # If root is not null
        self.dfs(root.left, path + [root.val]) # O(lgn)
        self.dfs(root.right, path + [root.val]) # O(lgn)
        
    def maxAncestorDiff(self, root: TreeNode) -> int:
        # use Depth Tree First Search algorithm
        # Want abs(diff) -> least value is 0
        self.returnVal = 0
        self.dfs(root, [])
        return self.returnVal

# One value in a list -> list is necessary, otherwise assignment issue happens
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        def dfs(node: TreeNode, max_: int, min_: int) -> None:
            if not node: # If root is null
                return
            # If root is not null
            max_ = max(max_, node.val)
            min_ = min(min_, node.val)
            ret[0]  = max(ret[0], max_- min_)

            dfs(node.left, max_, min_) # O(lgn)
            dfs(node.right, max_, min_) # O(lgn)

        # use Depth Tree First Search algorithm
        # Want abs(diff) -> least value is 0
        ret = [0]
        dfs(root, -float("inf"), float("inf"))
        return ret[0]
        
