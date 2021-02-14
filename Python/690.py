"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:

    def getImportance(self, employees: List['Employee'], id: int) -> int:
        # Visiting list
        que = deque([id])
        # Outlook dictionary
        dct = {emp.id : emp for emp in employees}
        # retValue
        impSum = 0
        while que:
            empID = que.popleft() # pop the first id in the queue
            impSum += dct[empID].importance
            for sub in dct[empID].subordinates:
                que.append(sub)
        return impSum
    
