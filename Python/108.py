# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balancer(self, nums: List[int], start: int, end: int) -> TreeNode:
        if start <= end:
            mid = start + (end - start) // 2;

            node = TreeNode(nums[mid])
            node.left = self.balancer(nums, start, mid -1);
            node.right = self.balancer(nums, mid + 1, end);
            return node;
        else:
            return None

    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        return self.balancer(nums, 0, len(nums) - 1);
