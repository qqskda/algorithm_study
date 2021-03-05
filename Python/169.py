class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # The question is asking to find the majority element.
        # Not with its count.

        # numCnt is 1 since 0 is within the number range
        theNum = 0
        numCnt = 1


        for num in nums:
            if num == theNum:
                numCnt += 1
            elif numCnt == 1:
                theNum = num
                numCnt = 1
            else:
                numCnt -= 1

        return theNum
                
