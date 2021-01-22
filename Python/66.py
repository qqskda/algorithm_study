# 36ms
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits[-1] == 9:
            if len(digits) == 1: #[9]
                return [1, 0]
            return self.plusOne(digits[:-1]) + [0] # last element is now 0
        else:
            digits[-1] += 1
        return digits

# 24ms - 98 faster
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for index in range (len(digits) - 1, -1, -1):
            if digits[index] != 9:
                digits[index] += 1
                return digits
            else:
                digits[index] = 0

        return [1] + digits
