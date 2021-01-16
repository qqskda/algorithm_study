class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # *zip(strs)    : ('flower',) ('flow',) ('flight',)
        # (*zip(*strs)) : ('f', 'f', 'f') ('l', 'l', 'l') ('o', 'o', 'i') ('w', 'w', 'g')
        # list(zip(*strs))  : [('f', 'f', 'f'), ('l', 'l', 'l'), ('o', 'o', 'i'), ('w', 'w', 'g')]

        words = list(zip(*strs))
        comPrefix = ""
        for word in words:
            if (len(set(word)) == 1): comPrefix += word[0]
            else: break

        return comPrefix

# This method is not a good idea in memory perspective
# as it jumps around the row but still faster than the above
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""

        minWord =  min(strs, key = len)
        comPrefix = ""
        for index in range (len(minWord)):
            for word in strs:
                if word[index] != minWord[index]:
                    return comPrefix
            comPrefix += minWord[index]
        return comPrefix
