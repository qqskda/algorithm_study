// Array
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.size() == 0) return 0;

        int dp[M.size()][M[0].size()][4];
        memset(dp, 0, sizeof(dp));

        int mRes = 0;

        for (int i = 0; i < M.size(); ++i){
            for (int j = 0; j < M[0].size(); ++j){
                 if (M[i][j] == 1){ // if that cell is positive value
                    dp[i][j][0] = j > 0 ? dp[i][j - 1][0] + 1 : 1;
                    dp[i][j][1] = i > 0 ? dp[i - 1][j][1] + 1 : 1;
                    dp[i][j][2] = (i > 0 && j > 0) ? dp[i - 1][j - 1][2] + 1 : 1;
                    dp[i][j][3] = (i > 0 && j < M[0].size() - 1) ? dp[i - 1][j + 1][3] + 1 : 1;
                    mRes = max({mRes, dp[i][j][0],  dp[i][j][1], dp[i][j][2], dp[i][j][3]});
                 }
            }
        }
        return mRes;
    }
};

// std::map
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.size() == 0) return 0;
        map<int, int> row, col, diag, ddiag;
        int mRes = 0;

        for (int i = 0; i < M.size(); ++i){
            for (int j = 0; j < M[0].size(); ++j){
                if (!M[i][j]){
                    row[i] = 0;
                    col[j] = 0;
                    diag[i+j] = 0;
                    ddiag[j-i] = 0;
                } else {
                    row[i]++;
                    col[j]++;
                    diag[i+j]++;
                    ddiag[j-i]++;
                    mRes = max({mRes, row[i], col[j], diag[j+i], ddiag[j-i]});
                }
            }
        }
        return mRes;
    }
};
