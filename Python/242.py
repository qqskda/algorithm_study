class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Counter is subclass of dict -> O(1) for finding the element
        # As it uses hash

        if len(s) != len(t) : return False
        return Counter(s) == Counter(t)
