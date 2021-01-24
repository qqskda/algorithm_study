class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return f'{(int(a, base = 2)+int(b, base = 2)) :b}'
        # or
        return bin(int(a, 2) + int(b,2))[2::]
