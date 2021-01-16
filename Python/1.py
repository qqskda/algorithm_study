class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashTable = {} # hash saves index of the element
        for index, elem in enumerate(nums):
            needNum = target - elem # we need this num to have target
            # it is in case needNum == elem -> to ensure have two of the same key
            # need to check it is not the same one by index
            if (needNum in hashTable) and (hashTable[needNum] != index):
                # we can return as the q is about two sums
                return list((index, hashTable[needNum]))
            hashTable[elem] = index
