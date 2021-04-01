class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int row = 1; row < m; ++row){
            for (int col = 1; col < n; ++col){
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }

        return dp[m-1][n-1];
    }
};

/*i
Each cell has unique paths from the start
Next cell add the prev cells.
Only down + right way - first row and col are all 1
Unique paths to the cell = uniquepaths above + left
*/
