import heapq
class Solution:
    def trapRainWater(self, h: List[List[int]]) -> int:
        n, m = len(h), len(h[0])
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        q = [] 

        for i in range(n):
            for j in range(m):
                if i == 0 or j == 0 or i == n - 1 or j == m - 1:
                    heapq.heappush(q, (h[i][j], i, j)) # (hight, x, y)
        
        vis = [[False for _ in range(m)] for _ in range(n)]
        ans = 0 
        while q:
            h_, x, y = heapq.heappop(q)
            if vis[x][y]:
                continue
            vis[x][y] = True
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and not vis[nx][ny]:
                    cr = max(h[x][y] - h[nx][ny], 0)
                    ans += cr 
                    h[nx][ny] += cr 
                    heapq.heappush(q, (h[nx][ny], nx, ny))

        return ans 

