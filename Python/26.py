class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0

        index = 0;

        for itr in range(1, len(nums)):
            if nums[index] != nums[itr]:
                index += 1
                nums[index] = nums[itr]

        return index + 1
