class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if len(nums) == 0: return 0
        index = 0
        for itr in range(len(nums)):
            if nums[itr] != val:
                nums[index] = nums[itr]
                index += 1
        return index
