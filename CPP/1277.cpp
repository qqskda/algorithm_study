class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ret = 0;
        int count = 0;
        for (int row = 1; row < matrix.size(); ++row){
            for(int col = 1; col < matrix[0].size(); ++col){
                int top = matrix[row-1][col];
                int left = matrix[row][col-1];
                int diag = matrix[row-1][col-1];

                if (top && left && matrix[row][col] && diag){
                    // side of n sqaure is fulfilled.
                    matrix[row][col] = min(diag, min(top, left)) + 1;
                }
                // cout << "ret: " << ret << " cell: " << matrix[row][col] << endl;
                ret += matrix[row][col];
            }
        }

        // First row all col
        for (auto elem : matrix.front()) ret += elem;
        // All row, first col
        for (auto elem : matrix) ret += elem.front();
        return ret - matrix[0][0];
    }
};

/*
  [0,1,1,1],
  [1,1,2,2],
  [0,1,2,3]
  three 2, two 1, one 3 -> 6 + 2 + 3 = 11
  first row + first col = 3 + 1 = 4
  add up = 15


*/
