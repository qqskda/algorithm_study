class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int sz = matrix.size();
        for (int row = 0; row < sz / 2; ++row){
            for (int col = row; col < sz - row - 1; ++col){

               swap(matrix[row][col], matrix[col][sz - 1 - row]);
                swap(matrix[row][col], matrix[sz - 1 - row][sz - 1 - col]);
                swap(matrix[row][col], matrix[sz - 1 - col][row]);
            }
        }
    }
};

/*
math:
Another Method = 90 clock wise = transpose + reverse
-> 90 anti = reverse, transpose


first row -> last col -> last row -> first col (spiral)
Each row and col covers half of the given length -> as it is somewhat swap-thing


Keep in mind that swap is done by its relative length from each side.
Top Side:   [0][1] -> 0 from top, 1 from left
Right Side: [1][2] -> 1 from top, 0 from right    -> row = col, col = relative to row
Bottom Side:[2][1] -> 0 from bottom, 1 from right -> row && col relative
Left Side:  [1][1] -> 1 from bottom, 0 from left  -> col = row, row = relative to col

top <-> left: row <-> col
top -> right | bottom = sz - top - 1

*/
