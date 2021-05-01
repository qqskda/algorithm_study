class Solution {
public:

    bool inBoard(int row, int col, const int& rowSz, const int& colSz){
        if (row >= 0 && row < rowSz){
            if (col >= 0 && col < colSz){
                return true;
            }
        }
        return false;
    }

    /*
    neighbours = {-1, 0, 1}

    Status:
    // % 2 == 1 -> alive in currGeneration
    // > 1 -> alive in nextGeneration
    aliveAlive = 3
    deadAlive = 2
    aliveDead = 1
    deadDead = 0
    */

    void gameOfLife(vector<vector<int>>& board) {
        int rowSz = board.size(), colSz = board.front().size();

        vector<int> indices = {-1, 0, 1};

        for (int row = 0; row < rowSz; ++row){
            for (int col = 0; col < colSz; ++col){
                int count = 0;

                for (auto& indexR : indices){
                    for (auto& indexC : indices){
                        int newRow = row + indexR;
                        int newCol = col + indexC;
                        if (inBoard(newRow, newCol, rowSz, colSz)){
                            // valid board access
                            if (board[newRow][newCol] % 2 == 1){
                                // if currently alive
                                count++;
                            }
                        }
                    }
                } // counting neighbours
                // Exlclude itself from the count
                count -= board[row][col];

                // apply rules: curr Implementation -> update ones will be alive

                if (count == 3 && board[row][col] == 0) board[row][col] = 2;
                else if (board[row][col] && (count < 4 && count > 1)) board[row][col] = 3;

            }
        } // Update boards

        // reform board into 0 1
        for (int row = 0; row < rowSz; ++row){
            for (int col = 0; col < colSz; ++col){
                if (board[row][col] > 1) board[row][col] = 1;
                else board[row][col] = 0;
            }
        }
    }
};

// Separated
class Solution {
private:
    int rowSz;
    int colSz;
    // horizontal, vertical, diagonal
    vector<int> paths = {-1, 0, 1};
public:

    bool isValid(const int row, const int col){
        if (row < rowSz && row >= 0){
            if (col < colSz && col >= 0){
                return true;
            }
        }
        return false;
    }

    int updateCell(const vector<vector<int>>& board, const int row, const int col){
        int cntAdj = 0;

        // for each direction, Count live adjacent neighbours
        for (auto& rPath : paths){
            for (auto& cPath : paths){
                // Check if valid access
                int adjRow = row + rPath, adjCol = col + cPath;
                if (isValid(adjRow, adjCol)){
                    // count of live cells in 3*3 including itself
                    if (board[adjRow][adjCol] % 2)
                        ++cntAdj;
                }
            }
        }
        // Checked 3*3 cells - itself
        cntAdj -= board[row][col];

        // update cell accordingly
        // aliveAlive = 3, deadAlive = 2, aliveDead = 1, deadDead = 0;
        if (cntAdj == 3 && board[row][col] == 0) return 2;
        else if (board[row][col] && (cntAdj < 4 && cntAdj > 1)) return 3;

        return board[row][col];
    }

    void gameOfLife(vector<vector<int>>& board) {
        // Update board sizes -> for range check before accessing an element
        this->rowSz = board.size(); this->colSz = board.front().size();

        for (int row = 0; row < rowSz; ++row){
            for (int col = 0; col < colSz; ++col){
                board[row][col] = updateCell(board, row, col);
            }
        } // for loop - entire board

        // Now reformat board into 0 and 1
        for (int row = 0; row < rowSz; ++row){
            for (int col = 0; col < colSz; ++col){
                if (board[row][col] > 1) board[row][col] = 1;
                else board[row][col] = 0;
            }
        } //
    }
};


/*
Rules: denote number of adjacent live cells = adjCells
if adjCells < 2 or adjCells > 3 -> dies in next generation
if == 3 -> lives in next generation

So we need two GameBoard state: current Generation and next generation
Implementation:
1. Have two boards -> space O(mn) where m = #rows n = #cols
2. Have one board -> space O(1) as it uses the existing board

// design
class Game{
    T& curr
    T& next
    boardSize
    // for data science, possible data members
    T& initial or initial cell status (# of liveCells) or called seed
    current live_cells
    soFarMaxLiveCellsCount ....

    // member functions
    ...
    randomSeed ...
}


*/
