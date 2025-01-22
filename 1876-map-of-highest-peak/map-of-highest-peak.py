from queue import Queue
from typing import List

class Solution:
    def highestPeak(self, a: List[List[int]]) -> List[List[int]]:
        n, m = len(a), len(a[0])
        q = Queue()
        
        vis = [[-1 for _ in range(m)] for _ in range(n)] 
        for i in range(n):
            for j in range(m):
                if a[i][j] == 1:
                    q.put((i, j))
                    a[i][j] = 0 
                    vis[i][j] = 0 
        
        dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        while not q.empty():
            x, y = q.get()
            for dx, dy in dir:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and vis[nx][ny] == -1:
                    a[nx][ny] = a[x][y] + 1
                    vis[nx][ny] = a[nx][ny]
                    q.put((nx, ny))
        
        return a