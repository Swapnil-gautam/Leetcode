class Solution:
    def bfs(self, board, visited, region, i, j):
        q = deque()
        q.append([i, j])
        region.append([i, j])
        visited[i][j] = 1
        edge = False

        while(q):
            x = q[0][0]
            y = q[0][1]

            q.popleft()

            # if(x-1 < 0 or y-1 < 0 or x >= len(board) or y >= len(board)):
            
            if(x == 0 or y == 0 or x == len(board)-1 or y == len(board[0])-1):
                # print("edge true")
                edge = True


            if(x-1 >= 0 and board[x-1][y] == "O" and visited[x-1][y] == 0):
                    q.append([x-1, y])
                    region.append([x-1, y])
                    visited[x-1][y] = 1
            if(x+1 < len(board) and board[x+1][y] == "O" and visited[x+1][y] == 0):
                    q.append([x+1, y])
                    region.append([x+1, y])
                    visited[x+1][y] = 1
            if(y-1 >= 0 and board[x][y-1] == "O" and visited[x][y-1] == 0):
                    q.append([x, y-1])
                    region.append([x, y-1])
                    visited[x][y-1] = 1
            if(y+1 < len(board[0]) and board[x][y+1] == "O" and visited[x][y+1] == 0):
                    q.append([x, y+1])
                    region.append([x, y+1])
                    visited[x][y+1] = 1
        
        return edge





    def solve(self, board: list[list[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        visited = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                
                if(board[i][j] == "O" and visited[i][j] == 0):
                    region = []
                    edge = self.bfs(board, visited, region, i, j)
                    if(edge == False):
                        for r in region:
                            board[r[0]][r[1]] = "X"



        