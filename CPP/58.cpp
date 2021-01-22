class Solution {
public:
    int lengthOfLastWord(string s) {
        int wordCount = 0;
        // Reverse reading.
        for (auto itr = s.rbegin(); itr != s.rend(); ++itr){
            if(*itr == ' '){
                if (wordCount) return wordCount;
                else continue;
            }
            else wordCount++;
        }
        return wordCount;
    }
};
