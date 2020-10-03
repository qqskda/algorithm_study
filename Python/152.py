// https://en.wikipedia.org/wiki/Maximum_subarray_problem

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        backNums = nums[::-1]
        for index in range(1, len(nums)):
            nums[index] *= nums[index-1] or 1
            backNums[index] *= backNums[index-1] or 1
        return max(nums+backNums)