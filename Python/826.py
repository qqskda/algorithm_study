# Runtime 336 ms, faster than 99.04%

class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        worker_len = len(worker)
        diff_len = len(difficulty)
        for i in range(diff_len):
            difficulty[i] = (difficulty[i], profit[i])
        difficulty.sort(key = lambda x:x[0])
        worker.sort() # If sort worker, doesnt have to start from the beginning
        sums = 0; most = 0; diff_index = 0
        for index in range(worker_len):
            while diff_index < diff_len and worker[index] >= difficulty[diff_index][0]:
                most = max(most, difficulty[diff_index][1])
                diff_index += 1
            sums += most
        return sums
```
Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100 
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get profit of [20,20,30,30] seperately.
```
        
                   