class Solution {
public:
    // The key point is number of distinct characters in each subarray.
    // Therefore, use frequency table to compare.
    // One vector contains all chars, one starts from none -> update by each char

    int numSplits(string s) {
        vector<int> freA(26,0), freB(26,0);
        int returnVal = 0, index = 0;
        int numA = 0, numB = 0;
        // freB -> num of each char
        // numB -> num of distinct char
        for (char c : s)  {
            freB[c - 'a']++;
            if(freB[c-'a'] == 1) numB++;
        }
        
        for (char c : s){
            index = c - 'a'; 
            freA[index]++;
            freB[index]--;
            if (freA[index] == 1) numA++; // Since index = 1 -> it is a distinct char
            if (freB[index] == 0) numB--; // Since index = 0 -> Lost one distinct charr
            if (numA == numB) returnVal++;
        }
        return returnVal;        
    }
};