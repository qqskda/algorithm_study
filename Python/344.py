class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        s.reverse()

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for index in range(0, len(s)//2):
            temp = s[index]
            s[index] = s[len(s)-1-index]
            s[len(s) -1 -index] = temp
