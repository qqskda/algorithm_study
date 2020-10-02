class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        while n > 0:
            if n == 1 or n == 2: return True;
            if n%2 != 0:
                return False
            n //= 2
        return False

# or
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return (n>0) and (n & (n-1))==0