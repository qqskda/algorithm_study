class Solution:
    def maxPower(self, s: str) -> int:
        # String length of 0, 1
        s_len = len(s)
        if s_len == 0: return 0
        if s_len == 1: return 1
        
        tracker = s[0]
        farMax = 0; count = 0; i = 0
        while s_len > i:
            if s[i] == tracker: 
                count += 1
            else:
                # New character
                tracker = s[i]
                farMax = max(farMax, count)
                count = 1
            i += 1
        # Incase s = one characters
        farMax = max(farMax, count)
                       
        return farMax
        
        