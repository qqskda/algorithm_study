class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # use XOR
        # a XOR a = 0
        # 0 XOR b = b
        # a XOR b XOR a = a XOR a XOR b = 0 XOR b = b
        # Therefore if there is only once element appears once -> xor will do the job

        a = 0
        for num in nums:
            a ^= num

        return a
