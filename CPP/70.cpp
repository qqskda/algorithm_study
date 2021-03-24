class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 1);

        // two options: inc by 1 or 2
        for (int i = 2; i <= n; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

/*
make dp[n] represents diff ways to reach n
filling up from low num
*/
