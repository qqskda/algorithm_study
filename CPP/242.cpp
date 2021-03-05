class Solution {
public:
    bool isAnagram(string s, string t) {
        // LowerString - Alphabets -> only 27 characters
        // Scan the first string theta(n), and second O(n)
        // So TimeComplexity: O(n), Space: theta(1) as it will always be 27 chars.

        // If length not same -> false
        if (s.length() != t.length()) return false;

        int cntTable[27] = {};

        for (char ch : s){
            cntTable[ch - 'a'] += 1;
        }

        for (char ch : t){
            if (cntTable[ch-'a'] == 0) return false;
            cntTable[ch - 'a'] -= 1;
        }

        return true;
    }
};
