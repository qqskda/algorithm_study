class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # Approach this question as in comparing the increment val vs maxSum val.
        inc = maxSum = nums[0]
        for num in nums[1:]:
            # if num > inc+num -> no reason to hold the previous numbers
            inc = max(num, inc+num)
            # if soFarMax < inc -> no reason to hold the previous numbers
            maxSum = max(maxSum, inc)

        return maxSum
        
