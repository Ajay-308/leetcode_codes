class Solution:
    def safe(self, board, row, col, n):
        for i in range(row):
            if board[i][col] == 'Q':
                return False
            for j in range(n):
                if board[i][j] == 'Q' and (abs(i - row) == abs(j - col)):
                    return False
        return True

    def solve(self, board, n, row, cnt):
        if row == n:
            cnt[0] += 1
            return

        for col in range(n):
            if self.safe(board, row, col, n):
                board[row][col] = 'Q'
                self.solve(board, n, row + 1, cnt)
                board[row][col] = '.'
                
    def totalNQueens(self, n: int) -> int:
        cnt = [0]
        board = [['.' for _ in range(n)] for _ in range(n)]
        self.solve(board, n, 0, cnt)
        
        return cnt[0]
