class Solution:
    def setZeroes(self, matrix):
        row = len(matrix)
        col = len(matrix[0])
        visit = [row[:] for row in matrix] 
        
        for i in range(row):
            for j in range(col):
                if matrix[i][j] == 0:
                    for k in range(col):
                        visit[i][k] = 0  
                    
        for i in range(row):
            for j in range(col):
                if matrix[i][j] == 0:
                    for k in range(row):
                        visit[k][j] = 0 
        
        for i in range(row):
            for j in range(col):
                matrix[i][j] = visit[i][j]
