class Solution:
    def findMaxFish(self, a: List[List[int]]) -> int:
        n, m = len(a), len(a[0])
        vis = [[False] * m for _ in range(n)]
        dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        def floodfill(x, y):
            ans = a[x][y]
            vis[x][y] = True 
            for dx, dy in dir:
                if 0 <= x + dx < n and 0 <= y + dy < m and not vis[x + dx][y + dy] and a[x + dx][y + dy] > 0:
                    ans += floodfill(x + dx, y + dy)
            return ans 

        res = 0 
        for i in range(n):
            for j in range(m):
                if a[i][j] > 0:
                    res = max(floodfill(i, j), res)
        
        return res 