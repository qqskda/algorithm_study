class Solution:
    def isPalindrome(self, s: str) -> bool:
        lt = 0; rt = len(s) - 1;

        while (lt < rt):
            if not s[lt].isalnum():
                lt += 1; continue;
            if not s[rt].isalnum():
                rt -= 1; continue;

            # both lt and rt are alphabets
            if (s[lt].lower() != s[rt].lower()):
                return False
            else:
                lt += 1; rt -= 1;

        return True
