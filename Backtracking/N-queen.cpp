class Solution {
private:
    bool safe(vector<string>& board, int row, int col, int n) {
        //check for same row ki same row mai q na aaye
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        //checking for upperleft daigonal mai q na aaya
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        //chekig for upperrigth diagonal mai q na aaye
        

        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (safe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, row + 1, n, ans);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(board, 0, n, ans);

        return ans;
    }
};
