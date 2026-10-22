class Solution:
    def bfs(self, grid, checked, i, j):
        q = deque()
        q.append([i, j])
        checked[i][j] = "1"
        while(q): 
            x = q[0][0]
            y = q[0][1]

            q.popleft()

            # print(x, y)
            if(x+1 < len(grid) and grid[x+1][y] == "1" and checked[x+1][y] == "0"):
                q.append([x+1, y])
                checked[x+1][y] = "1"

            if(y+1 < len(grid[0]) and grid[x][y+1] == "1" and checked[x][y+1] == "0"):
                q.append([x, y+1])
                checked[x][y+1] = "1"

            if(x-1 >= 0 and grid[x-1][y] == "1" and checked[x-1][y] == "0"):
                q.append([x-1, y])
                checked[x-1][y] = "1"

            if(y-1 >= 0 and grid[x][y-1] == "1" and checked[x][y-1] == "0"):
                q.append([x, y-1])
                checked[x][y-1] = "1"

                    
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        checked = [["0"]*n for _ in range(m)]

        count = 0
        for i in range(m):
            for j in range(n):
                if(grid[i][j] == "1" and checked[i][j] == "0"):
                    # print("*****************")
                    # print(i)
                    count += 1
                    self.bfs(grid, checked, i, j)

        return count


        