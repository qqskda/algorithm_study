class Solution:
    def numSplits(self, s: str) -> int:
        listA = [0] * 26 ; listB = [0] * 26
        numA = 0; numB = 0; returnVal = 0
        base = ord('a')
        for index in s:
            listB[ord(index) - base]+=1
            if listB[ord(index) - base] == 1: numB += 1
        
        for index in s:
            listA[ord(index) - base] += 1
            listB[ord(index) - base] -= 1
            if (listA[ord(index) - base] == 1): numA += 1
            if (listB[ord(index) - base] == 0): numB -= 1
            if (numA == numB): returnVal += 1
        return returnVal
        