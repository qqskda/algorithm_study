class Solution {
public:
    bool isPalindrome(string s) {
        // std::isalnum(ch) -> if alphabet
        // std::tolower(ch) -> lower the ch
        int lt = 0, rt = s.size() - 1;

        // Do not use == in case the length is odd.
        while (lt < rt){
            if (!std::isalnum(s[lt])) {lt++; continue;}
            if (!std::isalnum(s[rt])) {rt--; continue;}

            if (std::tolower(s[lt]) != std::tolower(s[rt])) return false;
            else {
                lt++; rt--;
            }
        }
        return true;
    }
};
