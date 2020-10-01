class Solution {
public:
    int maxPower(string s) {
        // Null string,  length 1
        if (s.size() == 0) return 0;
        else if (s.size() == 1) return 1;
        
        char tracker = s[0];
        int farMax = 0, count = 0;
        for (char c : s){
            if (c == tracker) count++;
            else{
                 // Update with new character
                tracker = c;
                // Update max value
                farMax = max(farMax, count);
                count = 1;
            }
        }
        // Incase the string consists of one characters.
        farMax = max(farMax, count);
        return farMax;
    }
};