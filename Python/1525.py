class Solution:
    def numSplits(self, s: str) -> int:
        if len(s) < 2: return 0
        
        listA = [0 for i in range(0,25)] ; listB = [0 for i in range(0,25)]
        numA = 0; numB = 0; returnVal = 0
        base = ord('a')
        for index in s:
            current = ord(index)
            listB[current - base]+=1
            if listB[current - base] == 1: numB += 1
        
        for index in s:
            current = ord(index)
            listA[current - base] += 1
            listB[current - base] -= 1
            if (listA[current - base] == 1): numA += 1
            if (listB[current - base] == 0): numB -= 1
            if (numA == numB): returnVal += 1
        return returnVal
        