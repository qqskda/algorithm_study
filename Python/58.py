class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        # do not forget range is half open
        for index in range(len(s)-1, -1, -1):
            print(s[index])
            if s[index] == ' ':
                if count: return count
                else: continue
            else: count += 1

        return count
