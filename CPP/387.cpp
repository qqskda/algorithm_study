class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() < 1) return -1;
        // Create map -> O(n)
        unordered_map<char, int> table;
        for (char ch : s){
            table[ch] += 1;
        }

        // find the first letter has table[index] = 1
        // O(n)
        for (int index = 0; index < s.size(); ++index){
            if (table[s[index]] == 1) return index;
        }
        return -1;
    }
};
