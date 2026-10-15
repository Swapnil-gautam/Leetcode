class Solution:
    def isToeplitzMatrix(self, matrix: list[list[int]]) -> bool:
        for i in range(0, len(matrix[0])):
            x = 0
            y = i
            while(x+1 < len(matrix) and y+1 < len(matrix[0])):
                if(matrix[x][y]  != matrix[x+1][y+1]):
                    return False
                x = x + 1
                y = y + 1

        for j in range(0, len(matrix)):
            x = j
            y = 0
            while(x+1 < len(matrix) and y+1 < len(matrix[0])):
                if(matrix[x][y]  != matrix[x+1][y+1]):
                    return False
                x = x + 1
                y = y + 1

        return True