class Solution:
    def reverse(self, x: int) -> int:
        res = int(str(abs(x))[::-1])
        # first () executes after check the if condition followed bit_length
        return (-res if x < 0 else res) if res.bit_length() < 32 else 0
