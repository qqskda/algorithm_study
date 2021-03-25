class Solution {
public:
    int countVowelStrings(int n) {
        // Remember dp method (adding up) requires N+1 size
        vector<vector<int>> dp(n+1, vector<int>(6,0));
        return helper(n, 5, dp);
    }

    //
    int helper(int n, int vowels, vector<vector<int>> &table){
        if (n == 1) return vowels;
        if (vowels == 1) return 1;
        if (table[n][vowels] != 0) return table[n][vowels];

        // Total comb of when n with vowels = all comb when n-1 + comb upto vowels -1 in n
        table[n][vowels] = helper(n-1, vowels, table) + helper(n, vowels - 1, table);
        return table[n][vowels];
    }
};

// Create 2D array for dp table

// n: 2, vowels : 2
// oo : o + u
// n: 2, vowels: 3
// ii : i(i + o + u) + o (o+u) + u(u)
// n: 3, vowels: 3
// iii : ii + io + iu
