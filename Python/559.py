"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root: return 0
        return self.getHeight(root, 1)


    def getHeight(self, root: 'Node', currentHeight: int) -> int:
        if not root.children: return currentHeight
        else:
            heightList = []
            for child in root.children:
                heightList.append(self.getHeight(child, currentHeight + 1))

        return max(heightList)

            
