class Solution:
    def isValid(self, s: str) -> bool:
        dic = {'(' : ')', '{' : '}', '[' : ']'}
        # first element is the key
        stk = []
        for ch in s:
            if ch in dic: # equal to == or == ...
                stk.append(ch)
            elif len(stk) == 0 or dic[stk.pop()] is not ch:
                return False
        return len(stk) == 0
