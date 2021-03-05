class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        # Two pointer method
        if len(nums) < 2: return

        slow = 0

        for fast in range(len(nums)):
            if nums[slow] == 0 and nums[fast] != 0:
                nums[slow], nums[fast] = nums[fast], nums[slow]
                slow += 1

            # If nums[slow] is not zero -> no swaps happening
            if nums[slow] != 0:
                slow += 1
                
