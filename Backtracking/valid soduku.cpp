class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!isValid(board, i, j, board[i][j])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
/*For non-empty cells (not containing '.'), it calls the isValid function to check the validity of that specific cell.
If any cell violates Sudoku rules, it immediately returns false.
If all cells pass the validity check, it returns true.*/

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c && i != row) {
                return false;
            }
            if (board[row][i] == c && i != col) {
                return false;
            }
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == c && (boxRow != row || boxCol != col)) {
                return false;
            }
        }
        return true;
    }
};

/*It checks three conditions to ensure that placing the number c in the given cell (row, col) is valid.
The first two if statements verify if c exists in the same row or column but in different cells. If it does, the placement is invalid.
The third if block checks the 3x3 subgrid containing the current cell. It calculates the subgrid's top-left cell and then checks if c already exists within that subgrid.
If any of these conditions fail for the given c at position (row, col), the function returns false. Otherwise, it returns true.
This combination of isValidSudoku and isValid functions allows for the comprehensive checking of each cell against the Sudoku rules, ensuring that the entire board is valid.*/
